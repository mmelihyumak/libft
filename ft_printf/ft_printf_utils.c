/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyumak <muyumak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 20:10:42 by muyumak           #+#    #+#             */
/*   Updated: 2022/12/09 17:36:20 by muyumak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_printstr(const char *s)
{
	int	length;

	length = 0;
	if (!s)
		return (ft_putstr("(null)"));
	return (ft_putstr(s));
}

int	ft_printnbr(int n)
{
	char	*number;
	int		len;

	number = ft_itoa(n);
	len = ft_putstr(number);
	free(number);
	return (len);
}

int	ft_printpercent(void)
{
	write(1, "%", 1);
	return (1);
}
