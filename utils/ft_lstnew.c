/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/22 14:11:24 by abeznik       #+#    #+#                 */
/*   Updated: 2021/11/06 18:39:27 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lists.h"

#include <stdlib.h> //malloc

t_list	*ft_lstnew(void *content, size_t line_nb)
{
	t_list	*element;

	element = (t_list *)malloc(sizeof(t_list));
	if (!element)
		return (NULL);
	element->content = content;
	element->line_nb = line_nb;
	element->next = NULL;
	return (element);
}

t_list	*add_link(t_list *list, char *content, size_t line_nb)
{
	t_list	*tmp;

	tmp = malloc(sizeof(t_list));
	if (tmp)
	{
		tmp->line_nb = line_nb;
		tmp->content = content;
		tmp->next = list;
	}
	return (tmp);
}
