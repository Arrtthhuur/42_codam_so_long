/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_check.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/07 14:18:52 by abeznik       #+#    #+#                 */
/*   Updated: 2021/11/07 16:27:42 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

#include <stdio.h>

static int	ret_ecp(int exist_e, int exist_c, int exist_p)
{
	if (exist_e == 0 || exist_c == 0 || exist_p == 0)
	{
		if (exist_e == 0)
			printf("Error\n\tMissing E.\n");
		if (exist_c == 0)
			printf("Error\n\tMissing C.\n");
		if (exist_p == 0)
			printf("Error\n\tMissing P.\n");
		return (1);
	}
	printf("Success\n\tFound at least one E, C and P.\n");
	return (0);
}

/*
** Function to check if there is at least one E, C and P.
*/
int	check_ecp(t_list *list, size_t line_nb)
{
	t_list	*tmp;
	int		exist_e;
	int		exist_c;
	int		exist_p;

	exist_e = 0;
	exist_c = 0;
	exist_p = 0;
	tmp = list;
	while (tmp->content != NULL)
	{
		if (tmp->line_nb > 0 && tmp->line_nb < line_nb - 1)
		{
			if (ft_strchr(tmp->content, 'E'))
				exist_e += 1;
			if (ft_strchr(tmp->content, 'C'))
				exist_c += 1;
			if (ft_strchr(tmp->content, 'P'))
				exist_p += 1;
		}
		tmp = tmp->next;
	}
	return (ret_ecp(exist_e, exist_c, exist_p));
}

static int	ret_lastl_len(t_list *tmp, size_t line_nb, size_t line_len)
{
	if (ft_strlen(tmp->content) != line_len)
	{
		printf("Error\n\tInvalid line length (see last line).");
		return (1);
	}
	return (0);
}

/*
** Function to check if all lines are the same length.
*/
int	check_len(t_list *list, size_t line_nb, size_t line_len)
{
	t_list	*tmp;
	size_t	count;

	count = 0;
	tmp = list;
	while (tmp && count < line_nb - 1)
	{
		if (tmp->line_nb == line_nb - 1)
		{
			if (ret_lastl_len(tmp, line_nb, line_len) != 0)
				return (1);
		}
		else
		{
			if (ft_strlen(tmp->content) - 1 != line_len)
			{
				printf("Error\n\tInvalid line length (see lines).");
				return (1);
			}
		}
		count++;
		tmp = tmp->next;
	}
	printf("Success\n\tLine length.\n");
	return (0);
}

static int	ret_ul_walls(t_list *tmp, size_t line_nb, size_t line_len)
{
	size_t	i;

	i = 0;
	while (i < line_len)
	{
		if (tmp->content[i] != '1')
		{
			printf("Error\n\tInvalid map (see upper or lower wall).\n");
			return (1);
		}
		i++;
	}
	return (0);
}

/*
** Function to check if the map is closed by walls.
*/
int	check_walls(t_list *list, size_t line_nb, size_t line_len)
{
	t_list	*tmp;
	int		i;

	tmp = list;
	while (tmp->content != NULL)
	{
		if (tmp->line_nb == 0 || tmp->line_nb == line_nb - 1)
		{
			if (ret_ul_walls(tmp, line_nb, line_len) != 0)
				return (1);
		}
		else
		{
			if (tmp->content[0] != '1'
				|| tmp->content[line_len - 1] != '1')
			{
				printf("Error\n\tInvalid map (see surrounding walls).\n");
				return (1);
			}
		}
		tmp = tmp->next;
	}
	printf("Success\n\tWalls.\n");
	return (0);
}
