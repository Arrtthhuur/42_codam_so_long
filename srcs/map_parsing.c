/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_read.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/21 21:21:29 by abeznik       #+#    #+#                 */
/*   Updated: 2021/10/21 21:21:29 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

#include <stdio.h>
#include <stdlib.h>

/*
** Function to print the linked list.
*/
static void	print_list(t_list *list)
{
	while (list->next != NULL)
	{
		printf("[%zu] %s\n", list->line_nb, list->content);
		list = list->next;
	}
}

/*
** Function to perform checks: length of lines, presence of walls,
** and exisiting at least one E, one C, and one P.
*/
static int	perform_checks(t_list *head, size_t line_nb, size_t line_len)
{
	if (check_len(head, line_nb, line_len) != 0)
		return (1);
	if (check_walls(head, line_nb, line_len) != 0)
		return (1);
	if (check_ecp(head, line_nb) != 0)
		return (1);
	printf("The map contains %zu lines of %zu length.\n", line_nb, line_len);
	return (0);
}

/*
** Function to read input file, create a linked list based on the 
** input and perform checks.
*/
int	map_read(int fd)
{
	size_t	line_nb;
	size_t	line_len;
	char	*line;
	t_list	*list;
	t_list	*head;

	head = NULL;
	list = NULL;
	line_nb = 0;
	line_len = 0;
	line = get_next_line(fd);
	line_len = ft_strlen(line) - 1;
	head = ft_lstadd_front(head, line, line_nb);
	while (line)
	{
		line_nb++;
		line = get_next_line(fd);
		head = ft_lstadd_back(head, line, line_nb);
	}
	print_list(head);
	return (perform_checks(head, line_nb, line_len));
}
