/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyumak <muyumak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:33:30 by muyumak           #+#    #+#             */
/*   Updated: 2022/12/09 17:40:42 by muyumak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_formats(va_list args, char format)
{
	int	length;

	length = 0;
	if (format == 'c')
		length += ft_putchar(va_arg(args, int));
	else if (format == 's')
		length += ft_printstr(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		length += ft_printnbr(va_arg(args, int));
	else if (format == 'p')
		length += ft_printptr(va_arg(args, uintptr_t));
	else if (format == 'u')
		length += ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		length += ft_printhex(format, va_arg(args, unsigned int));
	else if (format == '%')
		length += ft_printpercent();
	return (length);
}

int	ft_printf(const char *str, ...)
{
	int		length;
	va_list	args;
	int		i;

	va_start(args, str);
	length = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			length += ft_formats(args, str[i + 1]);
			i++;
		}
		else
			length += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (length);
}
