/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/22 14:37:18 by abeznik       #+#    #+#                 */
/*   Updated: 2021/10/26 17:04:27 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lists.h"

void	ft_lstadd_back(t_list **list, t_list *new)
{
	t_list	*last;

	if (list)
	{
		if (*list)
		{
			last = ft_lstlast(*list);
			last->next = new;
		}
		else
			*list = new;
	}
}
