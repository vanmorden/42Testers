/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fersance <fersance@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 16:41:37 by fersance          #+#    #+#             */
/*   Updated: 2025/05/10 18:15:41 by fersance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "ft_printf.h"
//#include <stdio.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int		i;

	i = 0;
	if (str == NULL)
		str = "(null)";
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr(unsigned int nb, int base)
{
	int		i;
	char	*base_set;
	int		count;

	count = 0;
	base_set = "0123456789abcdef";
	i = nb % base;
	if (nb / base > 0)
		count += ft_putnbr(nb / base, base);
	count += ft_putchar(base_set[i]);
	return (count);
}

int	print_d(int nb)
{
	int	count;

	count = 0;
	if (nb < 0)
	{
		count += ft_putchar('-');
		if (nb == -2147483648)
		{
			count += ft_putstr("2147483648");
			return (count);
		}
		nb = -nb;
	}
	count += ft_putnbr((unsigned int)nb, 10);
	return (count);
}

int	proccess_flags(char c, va_list ap)
{
	int	count;

	count = 0;
	if (c == 'd')
		count += print_d(va_arg(ap, int));
	else if (c == 'x')
		count += ft_putnbr(va_arg(ap, unsigned int), 16);
	else if (c == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (c == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(char *str, ...)
{
	va_list		ap;
	int			count;
	int			i;

	i = 0;
	count = 0;
	va_start(ap, str);
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			count += proccess_flags(str[i + 1], ap);
			if (str[i + 1] != '%')
				i++;
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(ap);
	return (count);
}

// int	main()
// {
// 	ft_printf("%d\n", 2147483680);
// 	printf("%d\n", 2147483680);
// 	ft_printf("%%d\n", 2147483680);
// 	printf("%%d");
// }
