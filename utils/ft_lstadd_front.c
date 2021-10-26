/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_front.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/22 14:24:33 by abeznik       #+#    #+#                 */
/*   Updated: 2021/10/26 16:59:06 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lists.h"

void	ft_lstadd_front(t_list **list, t_list *new)
{
	if (list)
	{
		if (*list)
			new->next = *list;
		*list = new;
	}
}
