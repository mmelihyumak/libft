/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyumak <muyumak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 20:59:02 by muyumak           #+#    #+#             */
/*   Updated: 2022/12/09 17:40:36 by muyumak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptrlen(uintptr_t ptr)
{
	int	i;

	i = 0;
	while (ptr != 0)
	{
		ptr /= 16;
		i++;
	}
	return (i);
}

void	ft_putptr(uintptr_t ptr)
{
	if (ptr >= 16)
	{
		ft_putptr(ptr / 16);
		ft_putptr(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_putchar((ptr + 48));
		else
			ft_putchar((ptr - 10) + 'a');
	}
}

int	ft_printptr(uintptr_t ptr)
{
	int	length;

	length = 0;
	length += write(1, "0x", 2);
	if (ptr == 0)
		length += write(1, "0", 1);
	else
	{
		ft_putptr(ptr);
		length += ft_ptrlen(ptr);
	}
	return (length);
}
