/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_characters.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/08 16:34:50 by abeznik       #+#    #+#                 */
/*   Updated: 2021/11/08 17:15:06 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*
** Function to check if there is only 1, 0, E, C or P in the map.
*/
int	check_char(t_list *list, size_t line_nb, size_t line_len)
{
	t_list	*tmp;
	size_t	count;
	size_t	i;

	count = 0;
	tmp = list;
	while (tmp && count < line_nb)
	{
		i = 0;
		while (i < line_len)
		{
			if (tmp->content[i] == '1' || tmp->content[i] == '0'
				|| tmp->content[i] == 'C' || tmp->content[i] == 'P'
				|| tmp->content[i] == 'E')
				i++;
			else
				return (error_msg("\tInvalid character.\n"));
		}
		count++;
		tmp = tmp->next;
	}
	return (success_msg("\tValid characters.\n"));
}
