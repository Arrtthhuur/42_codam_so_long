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
	while (list)
	{
		printf("[%zu] %s\n", list->line_nb, list->content);
		list = list->next;
	}
}

/*
** Function to compute the length of one line.
*/
static size_t	compute_line_len(t_list *list)
{
	size_t	len;

	len = 0;
	while (list->content[len] != '\n')
		len++;
	return (len);
}

/*
** Function to check if there is at least one E, C and P.
*/
static int	check_ecp(t_list *list, size_t line_nb)
{
	int	exist_e;
	int	exist_c;
	int	exist_p;

	exist_e = 0;
	exist_c = 0;
	exist_p = 0;
	while (list)
	{
		if (list->line_nb > 0 && list->line_nb < line_nb - 1)
		{
			if (ft_strchr(list->content, 'E'))
				exist_e += 1;
			if (ft_strchr(list->content, 'C'))
				exist_c += 1;
			if (ft_strchr(list->content, 'P'))
				exist_p += 1;
		}
		list = list->next;
	}
	if (exist_e == 0 || exist_c == 0 || exist_p == 0)
	{
		printf("Error\nMissing E, C or P\n");
		return (0);
	}
	printf("Success\nFound at least one E, C and P\n");
	return (1);
}

/*
** Function to check if all lines are the same length.
*/
static int	check_len(t_list *list, size_t line_nb, size_t line_len)
{
	size_t	len;
	size_t	lastl_len;
	size_t	count;

	len = 0;
	count = 0;
	while (list && count < line_nb)
	{
		if (list->line_nb == line_nb - 1)
		{
			if (ft_strlen(list->content) != line_len)
			{
				printf("Error\nInvalid line length (see last line)");
				return (0);
			}
		}
		else
		{
			if (ft_strlen(list->content) - 2 != line_len)
			{
				printf("Error\nInvalid line length (see lines)");
				return (0);
			}
		}
		list = list->next;
	}
	printf("Success\nLine length\n");
	return (1);
}

/*
** Function to check if the map is closed by walls.
*/
static int	check_walls(t_list *list, size_t line_nb, size_t line_len)
{
	int	i;

	while (list)
	{
		if (list->line_nb == 0 || list->line_nb == line_nb - 1)
		{
			i = 0;
			while (i < line_len)
			{
				if (list->content[i] != '1')
				{
					printf("Error\nInvalid map (see top or bottom wall)\n");
					return (0);
				}
				i++;
			}
		}
		else
		{
			i = 0;
			while (i < line_len)
			{
				if (list->content[0] != '1'
					|| list->content[line_len - 1] != '1')
				{
					printf("Error\nInvalid map (see surrounding walls)\n");
					return (0);
				}
				i++;
			}
		}
		list = list->next;
	}
	printf("Success\nWalls\n");
	return (1);
}

/*
** Function to read file and perform checks.
*/
int	map_read(int fd)
{
	size_t	line_nb;
	size_t	line_len;
	char	*line;
	t_list	*list;
	t_list	*map;

	list = NULL;
	line_nb = 0;
	line_len = 0;
	line = get_next_line(fd);
	line_len = ft_strlen(line) - 1;
	while (line)
	{
		// list = ft_lstnew(list, line, line_nb);
		list = ft_lstnew(line, line_nb);
		printf("%s\n", list->content);
		// print_list(list);
		line_nb++;
		ft_lstadd_back(map, list);
		// ft_lstadd_front(map, list);
		// printf("%s", line);
		line = get_next_line(fd);
	}
	// print_list(map);
	// print_list(*map);
	// printf("\n");
	// line_len = compute_line_len(*map);
	// if (!check_len(*map, line_nb, line_len))
	// 	return (0);
	// if (!check_walls(*map, line_nb, line_len))
	// 	return (0);
	// if (!check_ecp(*map, line_nb))
	// 	return (0);
	printf("The map contains %zu lines of %zu length.\n", line_nb, line_len);
	return (1);
}
