/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_g.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/07 17:27:55 by abeznik       #+#    #+#                 */
/*   Updated: 2021/12/11 16:57:02 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

#include <stdio.h> //printf

/*
** Function to check if there is at least one E, C and P.
*/
int	check_g(char **map, int nb_lines)
{
	char	**tmp;
	int		exist_g;
	int		y;

	exist_g = 0;
	y = 0;
	tmp = map;
	while (y < nb_lines)
	{
		if (y > 0 && y < nb_lines - 1)
		{
			if (ft_strchr(map[y], 'G'))
				exist_g += 1;
		}
		y++;
	}
	if (exist_g == 0)
	{
		printf("Error\n\tMissing G.\n");
		return (EXIT_FAILURE);
	}
	return (success_msg("\tFound at least one G.\n"));
}
