/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/22 14:37:18 by abeznik       #+#    #+#                 */
/*   Updated: 2021/11/07 15:29:19 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lists.h"

t_list	*ft_lstadd_back(t_list *head, char *content, size_t line_nb)
{
	t_list	*cursor;
	t_list	*new_node;

	cursor = head;
	while (cursor->next != NULL)
		cursor = cursor->next;
	new_node = ft_lstnew(content, line_nb, NULL);
	cursor->next = new_node;
	return (head);
}
