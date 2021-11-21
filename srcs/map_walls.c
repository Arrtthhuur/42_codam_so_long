/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_walls.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/07 14:18:52 by abeznik       #+#    #+#                 */
/*   Updated: 2021/11/08 17:14:11 by abeznik       ########   odam.nl         */
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
			return (error_msg("\tInvalid walls (see upper or lower wall).\n"));
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
				return (EXIT_FAILURE);
		}
		else
		{
			if (tmp->content[0] != '1'
				|| tmp->content[line_len - 1] != '1')
				return (error_msg("\tInvalid walls (see surrounding walls).\n"));
		}
		tmp = tmp->next;
	}
	return (success_msg("\tFound surrounding walls.\n"));
}
