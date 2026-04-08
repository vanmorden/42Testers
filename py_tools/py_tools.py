# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    py_tools.py                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cagomez- <fersance@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/25 17:08:13 by fersance          #+#    #+#              #
#    Updated: 2026/03/25 17:56:33 by cagomez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ...existing code...
import os
from pathlib import Path
import re

def generate_cur_ex_color():
    """
    Lee 'cur_ex.txt' en el mismo directorio, colorea bloques contiguos de caracteres
    (salvo '░') usando los marcadores $(CORANGE), $(CPURPLE), $(CYELLOW), $(CGREEN), $(CE).
    No resetea el color entre caracteres contiguos.
    Añade una línea de '░' arriba y otra abajo con el ancho de la línea más larga,
    prefijadas con '\t@echo "' y cerradas con '".
    Si alguna línea termina con ';' se elimina en el archivo final.
    Además añade una tabulación y un '@' delante de cada 'echo' de las líneas originales.
    """
    base = Path(__file__).parent
    in_path = base / "cur_ex.txt"
    out_path = base / "cur_ex_color.txt"

    if not in_path.exists():
        raise FileNotFoundError(f"No se encuentra el archivo de entrada: {in_path}")

    raw_lines = in_path.read_text(encoding="utf-8").splitlines()

    # --- Ajustables: columnas (1-based) desde el primer '░' donde empieza el cambio de color ---
    # Para las 3 primeras líneas: cambiar color a partir del carácter 61 (desde el primer '░')
    COLOR_SWITCH_FIRST = 61
    # Para las 3 últimas líneas: cambiar color a partir del carácter 20 (desde el primer '░')
    COLOR_SWITCH_LAST = 20
    # ---------------------------------------------------------------------------------------

    # Extraer el contenido dentro de comillas si existe para calcular ancho máximo
    contents = []
    prefixes = []
    suffixes = []
    for line in raw_lines:
        first_q = line.find('"')
        last_q = line.rfind('"')
        if first_q != -1 and last_q != -1 and last_q > first_q:
            prefix = line[:first_q+1]   # incluye la comilla de apertura
            content = line[first_q+1:last_q]
            suffix = line[last_q+1:]    # incluye cierre y posible ';' y espacios
        else:
            prefix = ""
            content = line
            suffix = ""
        prefixes.append(prefix)
        contents.append(content)
        suffixes.append(suffix)

    max_len = max((len(c) for c in contents), default=0)
    border = '░' * max_len

    out_lines = []

    # línea superior con tab y @echo "
    out_lines.append('\t@echo "' + border + '"')

    for idx, content in enumerate(contents):
        # Pad content to width
        padded = content + '░' * (max_len - len(content))
        chars = list(padded)

        # Índices de caracteres no-░
        non_block_idxs = [i for i, ch in enumerate(chars) if ch != '░']
        if not non_block_idxs:
            colored = ''.join(chars)
        else:
            first_nb, last_nb = non_block_idxs[0], non_block_idxs[-1]
            width_nb = last_nb - first_nb + 1

            # Encontrar el índice (0-based) del primer '░' en la línea (según requisito)
            try:
                first_block_idx = next(i for i, ch in enumerate(chars) if ch == '░')
            except StopIteration:
                first_block_idx = 0

            # Determinar columna deseada (0-based index) desde el primer '░'
            if idx < 3:
                desired_col_index = first_block_idx + (COLOR_SWITCH_FIRST - 1)
            else:
                desired_col_index = first_block_idx + (COLOR_SWITCH_LAST - 1)

            # split es el índice máximo que usa left_col; el cambio empieza en desired_col_index
            split = desired_col_index - 1

            # clamp split dentro del bloque observado (entre first_nb y last_nb)
            if split < first_nb:
                split = first_nb
            if split > last_nb:
                split = last_nb

            # Asignar colores según fila
            if idx < 3:
                left_col = "$(CORANGE)"
                right_col = "$(CPURPLE)"
            else:
                left_col = "$(CYELLOW)"
                right_col = "$(CGREEN)"

            CE = "$(CE)"
            out_chars = []
            i = 0
            while i < max_len:
                ch = chars[i]
                if ch == '░':
                    out_chars.append('░')
                    i += 1
                    continue

                # comienzo de segmento contiguo (no '░')
                color_for_segment = left_col if i <= split else right_col
                j = i
                # extender mientras sean no '░' y permanezcamos en el mismo lado del split
                while j < max_len and chars[j] != '░' and ((j <= split) == (i <= split)):
                    j += 1
                segment = ''.join(chars[i:j])
                out_chars.append(f"{color_for_segment}{segment}{CE}")
                i = j

            colored = ''.join(out_chars)

        # reconstruir la línea usando el prefijo original (si lo tenía) o manteniendo el contenido plano
        prefix = prefixes[idx]
        suffix = suffixes[idx]

        # eliminar ';' final si existe en la porción de sufijo o al final de la línea
        # conservando espacios finales
        if suffix:
            s_rs = suffix.rstrip()
            trailing_ws = suffix[len(s_rs):]
            if s_rs.endswith(';'):
                s_rs = s_rs[:-1]
            suffix = s_rs + trailing_ws
        else:
            # si no había sufijo pero la línea original terminaba en ';' dentro del content, eliminarlo
            if content.rstrip().endswith(';'):
                if colored.endswith(';'):
                    colored = colored[:-1]

        if prefix:
            # Si el prefijo contiene 'echo', normalizar a '\t@echo "' delante del contenido coloreado
            if re.search(r'\becho\b', prefix, re.IGNORECASE):
                m = re.search(r'(echo\s*")', prefix, re.IGNORECASE)
                if m:
                    echo_part = m.group(1)       # incluye la comilla de apertura
                else:
                    # fallback: usar la parte de prefix sin espacios y sin '@'
                    echo_part = prefix.strip().lstrip('@')
                    if not echo_part.endswith('"'):
                        echo_part += '"'
                new_prefix = '\t@' + echo_part
                line_out = new_prefix + colored + '"' + suffix
            else:
                line_out = prefix + colored + '"' + suffix
        else:
            # no había prefix (sin echo): conservar contenido coloreado sin comillas
            line_out = colored

        out_lines.append(line_out)

    # línea inferior con tab y @echo "
    out_lines.append('\t@echo "' + border + '"')

    out_path.write_text('\n'.join(out_lines) + '\n', encoding='utf-8')

if __name__ == "__main__":
    generate_cur_ex_color()
