/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyumak <muyumak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 02:58:06 by muyumak           #+#    #+#             */
/*   Updated: 2022/12/19 02:43:59 by muyumak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

char	*ft_read(int fd, char *filetext)
{
	char	*buff;
	int		rd_byte;

	rd_byte = 1;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (0);
	while (!ft_strchr(filetext) && rd_byte != 0)
	{
		rd_byte = read(fd, buff, BUFFER_SIZE);
		if (rd_byte == -1)
		{
			free(buff);
			return (0);
		}
		buff[rd_byte] = 0;
		filetext = ft_strjoin(filetext, buff);
	}
	free(buff);
	return (filetext);
}

char	*get_next_line(int fd)
{
	static char	*filetext[1024];
	char		*line;

	if (fd < 0 && BUFFER_SIZE <= 0)
		return (NULL);
	filetext[fd] = ft_read(fd, filetext[fd]);
	if (!filetext[fd])
		return (0);
	line = ft_get_line(filetext[fd]);
	filetext[fd] = ft_get_next_filetext(filetext[fd]);
	return (line);
}
