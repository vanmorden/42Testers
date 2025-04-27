/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fersance <fersance@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 16:53:42 by fersance          #+#    #+#             */
/*   Updated: 2025/04/27 16:54:56 by fersance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *str)
{
	int		i;
	char	*save;

	i = 0;
	while (str[i] != 0)
		i++;
	save = malloc(sizeof(char) * (i + 1));
 	if (!save)
		return (NULL);
	i = 0;
	while (str[i])
	{
		save[i] = str[i];
		i++;
	}
	save[i] = '\0';
	return (save);
}
