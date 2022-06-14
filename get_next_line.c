/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 13:45:35 by amateo-r          #+#    #+#             */
/*   Updated: 2022/03/10 12:39:32 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

void	ft_read(char **save, const int fd)
{
	char	*buffer;
	char	*tmp;
	int		i;

	buffer = malloc(BUFFER_SIZE + 1);
	if (read(fd, buffer, 0) >= 0 && buffer)
	{
		i = 1;
		while (!gnl_strchr(*save, '\n') && i > 0)
		{
			i = read(fd, buffer, BUFFER_SIZE);
			buffer[i] = '\0';
			if (!*save && i > 0)
				*save = gnl_substr(buffer, 0, i);
			else if (i > 0)
			{
				tmp = *save;
				*save = gnl_strjoin(*save, buffer);
			}
		}
	}
	free(buffer);
}

char	*build_line(char **save)
{
	char	*tmp;
	int		i;
	int		j;
	char	*line;

	if (!*save)
		return (0);
	if (gnl_strchr(*save, '\n'))
	{
		i = gnl_strlen(*save);
		j = gnl_strlen(gnl_strchr(*save, '\n'));
		line = gnl_substr(*save, 0, i - j + 1);
		tmp = *save;
		*save = gnl_substr(gnl_strchr(*save, '\n'), 1, j);
		free(tmp);
	}
	else
	{
		line = gnl_substr(*save, 0, gnl_strlen(*save));
		free(*save);
		*save = 0;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*save[FD_SETSIZE];

	ft_read(&save[fd], fd);
	if (BUFFER_SIZE < 1 || fd < 0 || fd > FD_SETSIZE)
		return (NULL);
	else
		return (build_line(&save[fd]));
}
