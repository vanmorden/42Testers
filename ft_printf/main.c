/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fersance <fersance@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 03:15:56 by fersance          #+#    #+#             */
/*   Updated: 2024/12/12 20:01:48 by fersance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "headers/libftprintf.h"

int	main(void)
{
	char			*texto = "Este es el texto a incrustar";
	int				an_int;
	unsigned int	an_uint;
	int				res_printf;
	int				res_ft_printf;

	an_int = 42;
	an_uint = 2147483648;
	//an_uint = 4294967295;

	char	*test = NULL;
	res_printf = printf("Probando un NULL: %s\n", test);
	res_ft_printf = ft_printf("Probando un NULL: %s\n", test);
	if (res_printf == res_ft_printf)
		printf("OK\n");
	else
		printf("KO %d, %d\n", res_printf, res_ft_printf);
	
	res_printf = printf("01 printf (s, X, int): %s - %X\n", texto, an_int);
	res_ft_printf = ft_printf("ft_printf (s, X, int): %s - %X\n", texto, an_int);
	if (res_printf == res_ft_printf)
		printf("OK\n");
	else
		printf("KO %d, %d\n", res_printf, res_ft_printf);

	res_printf = printf("02 printf (%%): %%z prueba\n");
	res_ft_printf = ft_printf("ft_printf (%%): %%z prueba\n");
	if (res_printf == res_ft_printf)
		printf("OK\n");
	else
		printf("KO %d, %d\n", res_printf, res_ft_printf);

	res_printf = printf("03 printf (i, int): %i\n", an_int);
	res_ft_printf = ft_printf("ft_printf (i, int): %i\n", an_int);
	if (res_printf == res_ft_printf)
		printf("OK\n");
	else
		printf("KO %d, %d\n", res_printf, res_ft_printf);

	res_printf = printf("04 printf (%%): %%z prueba\n");
	res_ft_printf = ft_printf("ft_printf (%%): %%z prueba\n");
	if (res_printf == res_ft_printf)
		printf("OK\n");
	else
		printf("KO %d, %d\n", res_printf, res_ft_printf);

	res_printf = printf("05 printf (u, uint): %u\n", an_uint);
	res_ft_printf = ft_printf("ft_printf (u, uint): %u\n", an_uint);
	if (res_printf == res_ft_printf)
		printf("OK\n");
	else
		printf("KO %d, %d\n", res_printf, res_ft_printf);

	res_printf = printf("06 printf (%%): %% prueba\n");
	res_ft_printf = ft_printf("ft_printf (%%): %% prueba\n");
	if (res_printf == res_ft_printf)
		printf("OK\n");
	else
		printf("KO %d, %d\n", res_printf, res_ft_printf);

	res_printf = printf("07 printf (d, int): %di\n", an_int);
	res_ft_printf = ft_printf("ft_printf (d, int): %di\n", an_int);
	if (res_printf == res_ft_printf)
		printf("OK\n");
	else
		printf("KO %d, %d\n", res_printf, res_ft_printf);

	res_printf = printf("08 printf (d, uint): %di\n", an_uint);
	res_ft_printf = ft_printf("ft_printf (d, uint): %di\n", an_uint);
	if (res_printf == res_ft_printf)
		printf("OK\n");
	else
		printf("KO %d, %d\n", res_printf, res_ft_printf);

	res_printf = printf("09 printf (%%): %% prueba\n");
	res_ft_printf = ft_printf("ft_printf (%%): %% prueba\n");
	if (res_printf == res_ft_printf)
		printf("OK\n");
	else
		printf("KO %d, %d\n", res_printf, res_ft_printf);

	res_printf = printf("10 printf (p, x, uint): %p - %x\n", texto, an_uint);
	res_ft_printf = ft_printf("ft_printf (p, x, uint): %p - %x\n", texto, an_uint);
	if (res_printf == res_ft_printf)
		printf("OK\n");
	else
		printf("KO %d, %d\n", res_printf, res_ft_printf);

	res_printf = printf("11 printf (c, x, uint): %c\n", '0');
	res_ft_printf = ft_printf("ft_printf (c, x, uint): %c\n", '0');
	if (res_printf == res_ft_printf)
		printf("OK\n");
	else
		printf("KO %d, %d\n", res_printf, res_ft_printf);

	res_printf = printf("12 printf (p, p): %p %p \n", LONG_MIN, LONG_MAX);
	res_ft_printf = ft_printf("ft_printf (p, p): %p %p \n", LONG_MIN, LONG_MAX);
	if (res_printf == res_ft_printf)
		printf("OK\n");
	else
		printf("KO %d, %d\n", res_printf, res_ft_printf);

	res_printf = printf("13 printf (p, p): %p %p \n", ULONG_MAX, -ULONG_MAX);
	res_ft_printf = ft_printf("ft_printf (p, p): %p %p \n", ULONG_MAX, -ULONG_MAX);
	if (res_printf == res_ft_printf)
		printf("OK\n");
	else
		printf("KO %d, %d\n", res_printf, res_ft_printf);

	res_printf = printf("14 printf (p, p): %p %p \n", 0, 0);
	res_ft_printf = ft_printf("ft_printf (p, p): %p %p \n", 0, 0);
	if (res_printf == res_ft_printf)
		printf("OK\n");
	else
		printf("KO %d, %d\n", res_printf, res_ft_printf);

	res_printf = printf("15 printf (d): %d %i\n", -10, -99);
	res_ft_printf = ft_printf("ft_printf (d): %d %i\n", -10, -99);
	if (res_printf == res_ft_printf)
		printf("OK\n");
	else
		printf("KO %d, %d\n", res_printf, res_ft_printf);

	res_printf = printf("16 printf (mix): %d %d %d %d %d %d %d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	res_ft_printf = ft_printf("ft_printf (mix): %d %d %d %d %d %d %d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	if (res_printf == res_ft_printf)
		printf("OK\n");
	else
		printf("KO %d, %d\n", res_printf, res_ft_printf);
}