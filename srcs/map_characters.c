/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_characters.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/08 16:34:50 by abeznik       #+#    #+#                 */
/*   Updated: 2021/12/11 17:00:36 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*
** Function to check if there is only 1, 0, E, C or P (or G) in the map.
*/
int	check_char(char **map, int nb_lines, int len_line)
{
	char	**tmp;
	int		x;
	int		y;

	y = 0;
	tmp = map;
	while (y < nb_lines)
	{
		x = 0;
		while (x < len_line)
		{
			if (tmp[y][x] == '1' || tmp[y][x] == '0'
				|| tmp[y][x] == 'C' || tmp[y][x] == 'P'
				|| tmp[y][x] == 'E' || tmp[y][x] == 'G')
				x++;
			else
				return (error_msg("\tInvalid character.\n"));
		}
		y++;
	}
	return (success_msg("\tValid characters.\n"));
}
