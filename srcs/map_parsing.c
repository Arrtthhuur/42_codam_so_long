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

#include <stdio.h> //printf

/*
** Function to print the linked list.
*/
void	print_list(t_list *list)
{
	while (list->next != NULL)
	{
		printf("[%zu] %s\n", list->line_nb, list->content);
		list = list->next;
	}
}

/*
** Function to perform checks: length of lines, presence of walls
** and existing at least one E, one C and one P.
*/
static int	perform_checks(t_list *head, size_t line_nb, size_t line_len)
{
	if (check_char(head, line_nb, line_len) != 0)
		return (EXIT_FAILURE);
	if (check_len(head, line_nb, line_len))
		return (EXIT_FAILURE);
	if (check_walls(head, line_nb, line_len))
		return (EXIT_FAILURE);
	if (check_ecp(head, line_nb))
		return (EXIT_FAILURE);
	printf("The map contains %zu lines of %zu length.\n", line_nb, line_len);
	return (EXIT_SUCCESS);
}

/*
** Function to read input file, create a linked list based on the 
** input and perform checks.
*/
int	map_read(t_img *img)
{
	size_t	line_nb;
	size_t	line_len;
	char	*line;

	img->list = NULL;
	line_nb = 0;
	line_len = 0;
	line = get_next_line(img->fd);
	line_len = ft_strlen(line);
	img->list = ft_lstadd_front(img->list, line, line_nb);
	while (line)
	{
		line_nb++;
		line = get_next_line(img->fd);
		img->list = ft_lstadd_back(img->list, line, line_nb);
	}
	print_list(img->list);
	img->nb_lines = line_nb - 1;
	img->len_line = line_len;
	return (perform_checks(img->list, line_nb, line_len));
}
