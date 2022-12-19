/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyumak <muyumak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:34:13 by muyumak           #+#    #+#             */
/*   Updated: 2022/12/09 17:58:19 by muyumak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
int		ft_putchar(int c);
int		ft_formats(va_list args, char format);
int		ft_putstr(const char *s);
size_t	ft_strlen(const char *str);
char	*ft_itoa(int n);
int		ft_printptr(uintptr_t ptr);
int		ft_printhex(char format, unsigned int num);
int		ft_printpercent(void);
int		ft_printnbr(int n);
int		ft_printstr(const char *s);
int		ft_print_unsigned(unsigned int num);

#endif