/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyumak <muyumak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 02:58:25 by muyumak           #+#    #+#             */
/*   Updated: 2022/12/13 03:02:32 by muyumak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

char	*ft_strchr(char *str);
char	*ft_strjoin(char *str, char *buff);
char	*ft_get_line(char *filetext);
char	*ft_get_next_filetext(char *filetext);
char	*get_next_line(int fd);
char	*ft_read(int fd, char *filetext);
size_t	ft_strlen(char *str);

#endif