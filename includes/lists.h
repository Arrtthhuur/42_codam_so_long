/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lists.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/25 15:50:16 by abeznik       #+#    #+#                 */
/*   Updated: 2021/10/25 15:50:16 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTS_H
# define LISTS_H

# include <stddef.h> //size_t

typedef struct s_list
{
	size_t			line_nb;
	char			*content;
	struct s_list	*next;
}					t_list;

t_list	*ft_lstnew(void *content, size_t line_nb, t_list *next);
t_list	*ft_lstadd_front(t_list *head, char *content, size_t line_nb);
t_list	*ft_lstadd_back(t_list *head, char *content, size_t line_nb);
void	print_list(t_list *list);

#endif