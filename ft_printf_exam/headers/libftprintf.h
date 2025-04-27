/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fersance <fersance@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 02:10:30 by fersance          #+#    #+#             */
/*   Updated: 2024/12/12 19:36:52 by fersance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
//# include <stdint.h>

size_t	ft_nbrlen(long long number);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
char	*ft_itoa_base(int numb, int base, int lowercase);
char	*ft_utoa_base(unsigned long long numb, int base, int lowercase);
char	*ft_strdup(const char *s);
int		ft_printf(char const *buffer, ...);

#endif // LIBFTPRINTF_H
