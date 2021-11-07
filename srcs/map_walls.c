/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_walls.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/07 14:18:52 by abeznik       #+#    #+#                 */
/*   Updated: 2021/11/07 17:40:16 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

#include <stdio.h> //printf

static int	ret_ul_walls(t_list *tmp, size_t line_len)
{
	size_t	i;

	i = 0;
	while (i < line_len)
	{
		if (tmp->content[i] != '1')
		{
			printf("Error\n\tInvalid map (see upper or lower wall).\n");
			return (1);
		}
		i++;
	}
	return (0);
}

/*
** Function to check if the map is closed by walls.
*/
int	check_walls(t_list *list, size_t line_nb, size_t line_len)
{
	t_list	*tmp;

	tmp = list;
	while (tmp->content != NULL)
	{
		if (tmp->line_nb == 0 || tmp->line_nb == line_nb - 1)
		{
			if (ret_ul_walls(tmp, line_len) != 0)
				return (1);
		}
		else
		{
			if (tmp->content[0] != '1'
				|| tmp->content[line_len - 1] != '1')
			{
				printf("Error\n\tInvalid map (see surrounding walls).\n");
				return (1);
			}
		}
		tmp = tmp->next;
	}
	printf("Success\n\tWalls.\n");
	return (0);
}
