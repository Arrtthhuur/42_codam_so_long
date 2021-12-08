/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_len.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/07 17:26:53 by abeznik       #+#    #+#                 */
/*   Updated: 2021/12/08 17:01:26 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*
** Function to check if all lines are the same length.
*/
int	check_len(char **map, int nb_lines, int len_line)
{
	char	**tmp;
	int		y;

	y = 0;
	tmp = map;
	while (y < nb_lines)
	{
		if ((int)ft_strlen(map[y]) != len_line)
			return (error_msg("\tInvalid line length (see lines).\n"));
		y++;
	}
	return (success_msg("\tValid line length.\n"));
}
