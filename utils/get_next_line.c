/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/16 12:26:44 by abeznik       #+#    #+#                 */
/*   Updated: 2021/10/21 21:45:51 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

#include <unistd.h> // read
#include <stdlib.h> // free

# define BUFFER_SIZE 29

static void	free_ptr(char *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}

/*
**	If a newline is found in the static variable save, the contents until
**	'\n' are copied to line and the rest is stored again in save. If no
**	newline is found, the whole content of save is copied to line and save
**	points to NULL. 
*/

static char	*get_line(char **line, char **save)
{
	int		len;

	len = 0;
	while ((*save)[len] != '\n' && (*save)[len] != '\0')
		len++;
	if (ft_strchr(*save, '\n'))
	{
		*line = ft_substr(*save, 0, len + 1);
		*save = ft_strdup(*save + len + 1);
		if (!*save)
			return (NULL);
	}
	else
	{
		*line = ft_strdup(*save);
		free_ptr(*save);
	}
	if (!*line)
	{
		free_ptr(*line);
		return (NULL);
	}
	return (*line);
}


/*
**	This function copies BUFFER_SIZE bytes from the string buffer to the
**	static variable save until a newline is found or the end of file is
**	reached.
*/

static int	read_file(int fd, char **buffer, char **save, char **line)
{
	int		nbytes;

	nbytes = 1;
	while (!ft_strchr(*save, '\n') && nbytes)
	{
		nbytes = read(fd, *buffer, BUFFER_SIZE);
		(*buffer)[nbytes] = '\0';
		*save = ft_strjoin(*save, *buffer);
		if (!*save)
			return (0);
	}
	free_ptr(*buffer);
	get_line(line, save);
	return (nbytes);
}

/*
** 	This function returns the next line from the fd with its respective '\n',
**	or the last line of the file. It returns null if there's nothing to read
**	or if an error occurs.
*/

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;
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
	{
		save = ft_strdup("");
		if (!save)
			return (NULL);
	}
	if (read_file(fd, &buffer, &save, &line) == 0 && *line == '\0')
	{
		if (line)
			free_ptr(line);
		return (NULL);
	}
	return (line);
}
