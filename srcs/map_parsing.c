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

#include <stdio.h> //printf

/*
** Function to perform checks: length of lines, presence of walls
** and existing at least one E, one C and one P.
*/
static int	perform_checks(char **map, int nb_lines, int len_line)
{
	if (check_char(map, nb_lines, len_line))
		return (EXIT_FAILURE);
	if (check_len(map, nb_lines, len_line))
		return (EXIT_FAILURE);
	if (check_walls(map, nb_lines, len_line))
		return (EXIT_FAILURE);
	if (check_ecp(map, nb_lines))
		return (EXIT_FAILURE);
	if (check_g(map, nb_lines))
		return (EXIT_FAILURE);
	printf("The map contains %d lines of %d length.\n", nb_lines, len_line);
	return (EXIT_SUCCESS);
}

/*
** Function to compute number of lines, and thus allowing
** us to know how much space to allocate.
*/
int	map_first_read(t_img *img)
{
	char	*line;
	int		nb_lines;

	nb_lines = 0;
	line = get_next_line(img->fd1);
	while (line)
	{
		free(line);
		nb_lines++;
		line = get_next_line(img->fd1);
	}
	free(line);
	return (nb_lines);
}

/*
** Function to read input file, create a linked list based on the 
** input and perform checks.
*/
int	map_read(t_img *img)
{
	char	**map;
	int		line_len;
	int		i;
	int		y;

	line_len = 0;
	y = 0;
	i = map_first_read(img);
	map = (char **)malloc(sizeof(map) * (i + 1));
	if (!map)
		return (1);
	map[y] = get_next_line(img->fd2);
	line_len = ft_strlen(map[y]);
	while (map[y])
	{
		y++;
		map[y] = get_next_line(img->fd2);
	}
	map[y] = NULL;
	img->map = map;
	img->nb_lines = i;
	img->len_line = line_len;
	return (perform_checks(img->map, img->nb_lines, img->len_line));
}
