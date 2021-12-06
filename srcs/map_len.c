/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_len.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/07 17:26:53 by abeznik       #+#    #+#                 */
/*   Updated: 2021/11/24 14:14:44 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	ret_lastl_len(t_list *tmp, size_t line_len)
{
	if (ft_strlen(tmp->content) != line_len)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
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
	while (tmp && count < line_nb)
	{
		if (ft_strlen(tmp->content) != line_len)
			return (error_msg("\tInvalid line length (see lines).\n"));
		count++;
		tmp = tmp->next;
	}
	return (success_msg("\tValid line length.\n"));
}
