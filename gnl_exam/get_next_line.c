/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fersance <fersance@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 16:49:52 by fersance          #+#    #+#             */
/*   Updated: 2025/05/10 18:49:14 by fersance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *str)
{
	int		len;
	char	*save;

	len = 0;
	while (str[len] != 0)
		len++;
	save = malloc(sizeof(char) * (len + 1));
	if (!save)
		return (NULL);
	while (len > -1)
	{
		save[len] = str[len];
		len--;
	}
	return (save);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	static int	buffer_read;
	static int	buffer_pos;
	int			i;
	char		line[70000];

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (i < buffer_pos)
	{
		line[i] = '\0';
		i++;
	}
	i = 0;
	while (1)
	{
		if (buffer_pos >= buffer_read)
		{
			buffer_read = read(fd, buffer, BUFFER_SIZE);
			buffer_pos = 0;
			if (buffer_read == 0 && i > 0)
			{
				line[i] = '\0';
				return (ft_strdup(line));
			}
			if (buffer_read <= 0)
			{
				if (i>0)
					i = 0;
				break ;
			}
		}
		line[i] = buffer[buffer_pos++];
		i++;
		if (line[i - 1] == '\n')
			break ;
	}
	line[i] = '\0';
	if (i == 0)
		return (NULL);
	return (ft_strdup(line));
}

// int main()
// {
// 	int fd = open("t.txt", O_RDONLY);

// 	printf("%s\n", get_next_line(fd));
// }
