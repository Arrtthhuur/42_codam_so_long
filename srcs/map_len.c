/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_len.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/07 17:26:53 by abeznik       #+#    #+#                 */
/*   Updated: 2021/11/07 18:06:41 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

#include <stdio.h> //printf

static int	ret_lastl_len(t_list *tmp, size_t line_len)
{
	if (ft_strlen(tmp->content) != line_len)
	{
		printf("Error\n\tInvalid line length (see last line).");
		return (1);
	}
	return (0);
}

/*
** Function to check if all lines are the same length.
*/
int	check_len(t_list *list, size_t line_nb, size_t line_len)
{
	t_list	*tmp;
	size_t	count;

	count = 0;
	tmp = list;
	while (tmp && count < line_nb - 1)
	{
		if (tmp->line_nb == line_nb - 1)
		{
			if (ret_lastl_len(tmp, line_len) != 0)
				return (1);
		}
		else
		{
			if (ft_strlen(tmp->content) - 1 != line_len)
			{
				printf("Error\n\tInvalid line length (see lines).");
				return (1);
			}
		}
		count++;
		tmp = tmp->next;
	}
	printf("Success\n\tLine length.\n");
	return (0);
}
