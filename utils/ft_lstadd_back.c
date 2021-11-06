/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/22 14:37:18 by abeznik       #+#    #+#                 */
/*   Updated: 2021/11/06 18:35:16 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lists.h"

// void	ft_lstadd_back(t_list *lst, t_list *new)
// {
// 	t_list	*last;

// 	if (lst)
// 	{
// 		last = ft_lstlast(lst);
// 		last->next = new;
// 	}
// 	else
// 		lst = new;
// }

void	ft_lstadd_back(t_list *list, t_list *new)
{
	t_list	*temp;

	temp = list;
	while (temp != NULL && temp->next != NULL)
		temp = temp->next;
	temp->next = new;
	// printf("DATA INSERTED SUCCESSFULLY\n");
}
