/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/21 21:22:17 by abeznik       #+#    #+#                 */
/*   Updated: 2021/10/21 21:22:17 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

#include <stdio.h> // printf
#include <unistd.h> // close
#include <stdlib.h> // free

// #include <sys/stat.h>
#include <fcntl.h> // open

t_list	*add_link(t_list *list, char *line)
{
	t_list	*tmp;

	tmp = malloc(sizeof(t_list));
	if (tmp)
	{
		tmp->content = line;
		tmp->next = list;
	}
	return (tmp);
}

static void	print_list(t_list *list)
{
	while (list)
	{
		printf("%s", list->content);
		list = list->next;
	}
}

static int	map_read(int fd)
{
	char	*line;
	t_list	*list;
	t_list	**map;

	list = NULL;
	line = get_next_line(fd);
	while (line)
	{
		list = ft_lstnew(line);
		// list = add_link(list, line);
		ft_lstadd_front(map, list);
		line = get_next_line(fd);
	}
	while (*map)
	{
		printf("%s", map->content);
		map = map->next;
		// print_list(*map);
	}
	printf("size: %d\n", ft_lstsize(*map));
	return (1);
}

// int	main(int argc, char *argv[])
// {
// 	int		fd;
// 	int		fd_copy;

// 	if (argc < 2)
// 	{
// 		printf("Error\nNo map entered!");
// 	}
// 	else
// 	{
// 		fd = open(argv[1], O_RDONLY);
// 		// fd_copy = open(argv[1], O_RDONLY);
// 		// map_check(fd, fd_copy);
// 		map_read(fd);
// 		close(fd);
// 	}
// 	return (0);
// }

int	main(void)
{
	int		fd;

	fd = open("simple_valid.ber", O_RDONLY);
	map_read(fd);
	close(fd);
	return (0);
}