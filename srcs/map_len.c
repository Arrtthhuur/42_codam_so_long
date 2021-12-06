/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_len.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/07 17:26:53 by abeznik       #+#    #+#                 */
/*   Updated: 2021/12/06 20:08:19 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*
** Function to check if all lines are the same length.
*/
int	check_len(char **map, size_t nb_lines, size_t len_line)
{
	char	**tmp;
	size_t	x;
	size_t	y;

	y = 0;
	tmp = map;
	while (y < nb_lines)
	{
		if (ft_strlen(map[y]) != len_line)
			return (error_msg("\tInvalid line length (see lines).\n"));
		y++;
	}
	return (success_msg("\tValid line length.\n"));
}
