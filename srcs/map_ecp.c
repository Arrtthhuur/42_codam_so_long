/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_ecp.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/07 17:27:55 by abeznik       #+#    #+#                 */
/*   Updated: 2021/12/08 17:01:21 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

#include <stdio.h> //printf

static int	ret_ecp(int exist_e, int exist_c, int exist_p)
{
	if (exist_e == 0 || exist_c == 0 || exist_p == 0)
	{
		if (exist_e == 0)
			printf("Error\n\tMissing E.\n");
		if (exist_c == 0)
			printf("Error\n\tMissing C.\n");
		if (exist_p == 0)
			printf("Error\n\tMissing P.\n");
		return (EXIT_FAILURE);
	}
	return (success_msg("\tFound at least one E, C and P.\n"));
}

/*
** Function to check if there is at least one E, C and P.
*/
int	check_ecp(char **map, int nb_lines)
{
	char	**tmp;
	int		exist_e;
	int		exist_c;
	int		exist_p;
	int		y;

	exist_e = 0;
	exist_c = 0;
	exist_p = 0;
	y = 0;
	tmp = map;
	while (y < nb_lines)
	{
		if (y > 0 && y < nb_lines - 1)
		{
			if (ft_strchr(map[y], 'E'))
				exist_e += 1;
			if (ft_strchr(map[y], 'C'))
				exist_c += 1;
			if (ft_strchr(map[y], 'P'))
				exist_p += 1;
		}
		y++;
	}
	return (ret_ecp(exist_e, exist_c, exist_p));
}
