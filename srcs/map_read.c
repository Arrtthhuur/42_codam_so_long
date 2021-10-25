/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_read.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/21 21:21:29 by abeznik       #+#    #+#                 */
/*   Updated: 2021/10/21 21:21:29 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

#include <stdio.h>
#include <stdlib.h>

static size_t	total_lines(int fd)
{
	char	*line;
	size_t	line_count;

	line_count = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		line_count++;
		line = get_next_line(fd);
	}
	return (line_count);
}

static int	line_len(char *line)
{
	int	len;

	len = 0;
	while (line[len] != '\n' && line)
		len++;
	return (len);
}

static int	check_walls(int fd, size_t line_count)
{
	char	*line;
	int		line_nb;
	int		len;
	int		i;

	line_nb = 0;
	len = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		len = line_len(line);
		line_nb++;
		i = 0;
		if (line_nb == 1)
		{
			while (i < len - 1 || line_nb == line_count)
			{
				if (line[i] != '1')
					return (0);
				i++;
			}
		}
		else if (line_nb > 1 && line_nb < line_count)
		{
			while (i < len - 1)
			{
				if (line[0] != '1' || line[len - 2] != '1')
					return (0);
				i++;
			}
		}
		line = get_next_line(fd);
	}
	return (1);
}

int	map_check(int fd, int fd_copy)
{
	size_t	line_count;

	line_count = total_lines(fd_copy);
	if (!check_walls(fd, line_count))
	{
		printf("Error\nMap invalid!");
		return (0);
	}
	// if (!check_len(fd))
	printf("\nall good");
	return (1);
}
