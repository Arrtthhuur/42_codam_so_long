/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_front.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/22 14:24:33 by abeznik       #+#    #+#                 */
/*   Updated: 2021/11/07 15:29:12 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lists.h"

t_list	*ft_lstadd_front(t_list *head, char *content, size_t line_nb)
{
	t_list	*element;

	element = ft_lstnew(content, line_nb, head);
	head = element;
	return (head);
}
