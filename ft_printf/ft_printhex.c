/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyumak <muyumak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 21:19:47 by muyumak           #+#    #+#             */
/*   Updated: 2022/12/09 17:35:54 by muyumak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(int c)
{
	write(1, &c, 1);
}

int	ft_divide(unsigned int num)
{
	unsigned int	nbr;
	int				length;

	length = 0;
	nbr = num;
	while (nbr > 0)
	{
		nbr /= 16;
		length += 1;
	}
	return (length);
}

int	ft_printhex(char format, unsigned int num)
{
	int	length;

	length = 0;
	if (num > 0)
		length = ft_divide(num);
	if (num >= 16)
	{
		ft_printhex(format, num / 16);
		ft_printhex(format, num % 16);
	}
	else if (num > 0 && num < 10)
		ft_puthex(num + 48);
	else if (num >= 10 && num < 16)
	{
		if (format == 'x')
			ft_puthex(num - 10 + 97);
		else if (format == 'X')
			ft_puthex(num - 10 + 65);
	}
	else if (num == 0)
	{
		ft_puthex(48);
		length++;
	}
	return (length);
}

int	ft_print_unsigned(unsigned int num)
{
	int				length;
	unsigned int	nbr;

	length = 0;
	nbr = num;
	while (nbr > 0)
	{
		nbr /= 10;
		length++;
	}
	if (num > 9)
	{
		ft_print_unsigned(num / 10);
		ft_print_unsigned(num % 10);
	}
	else if (num > 0 && num <= 9)
	{
		ft_putchar((num + 48));
	}
	else if (num == 0)
	{
		ft_putchar('0');
		length++;
	}
	return (length);
}
