/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/16 12:26:44 by abeznik       #+#    #+#                 */
/*   Updated: 2021/11/06 17:59:08 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

#include <unistd.h> // read
#include <stdlib.h> // free

static void	gnl_free(char *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}

static int	gnl_line_len(char **save)
{
	int	len;

	len = 0;
	while ((*save)[len] != '\n' && (*save)[len] != '\0')
		len++;
	return (len);
}

static char	*gnl_new_line(char **line, char **save)
{
	char	*tmp_save;
	int		len;

	len = gnl_line_len(save);
	tmp_save = *save;
	if (ft_strchr(*save, '\n'))
	{
		*line = ft_substr(*save, 0, len);
		*save = ft_strdup(*save + len + 1);
		if (!*save)
			return (NULL);
	}
	else
	{
		*line = ft_strdup(tmp_save);
		*save = NULL;
	}
	if (!*line)
	{
		gnl_free(*line);
		return (NULL);
	}
	gnl_free(tmp_save);
	return (*line);
}

static int	gnl_read_file(int fd, char **buffer, char **save, char **line)
{
	int		nbytes;
	char	*tmp;

	nbytes = 1;
	while (!ft_strchr(*save, '\n') && nbytes != 0)
	{
		nbytes = read(fd, *buffer, BUFFER_SIZE);
		(*buffer)[nbytes] = '\0';
		tmp = *save;
		*save = ft_strjoin(*save, *buffer);
		if (!*save)
			return (0);
		gnl_free(tmp);
	}
	gnl_free(*buffer);
	gnl_new_line(line, save);
	return (nbytes);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;
	char		*buffer;

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (read(fd, buffer, 0) < 0)
	{
		free(buffer);
		return (NULL);
	}
	if (!save)
		save = ft_strdup("");
	if (!save)
		return (NULL);
	if (gnl_read_file(fd, &buffer, &save, &line) == 0 && *line == '\0')
	{
		if (line)
			gnl_free(line);
		return (NULL);
	}
	return (line);
}
