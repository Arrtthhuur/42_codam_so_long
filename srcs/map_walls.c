/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_walls.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/07 14:18:52 by abeznik       #+#    #+#                 */
/*   Updated: 2021/12/06 20:16:39 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

#include <stdio.h> //printf

/*
** Function to check if the map is closed by walls.
*/
int	check_walls(char **map, size_t nb_lines, size_t len_line)
{
	char	**tmp;
	size_t	x;
	size_t	y;

	y = 0;
	tmp = map;
	while (y < nb_lines)
	{
		if (y == 0 || y == nb_lines - 1)
		{
			x = 0;
			while (x < len_line)
			{
				if (tmp[y][x] != '1')
					return (error_msg("\tInvalid walls (see upper or lower wall).\n"));
				x++;
			}
		}
		else
		{
			if (tmp[y][0] != '1' || tmp[y][len_line - 1] != '1')
				return (error_msg("\tInvalid walls (see middle wall).\n"));
		}
		y++;
	}
	return (success_msg("\tFound surrounding walls.\n"));
}
