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
#include <fcntl.h> // open

// int	main(int argc, char *argv[])
// {
// 	int		fd;

// 	if (argc < 2)
// 	{
// 		printf("Error\nNo map entered!");
// 	}
// 	else
// 	{
// 		fd = open(argv[1], O_RDONLY);
// 		map_read(fd);
// 		close(fd);
// 	}
// 	return (0);
// }

int	main(void)
{
	int		fd;

	fd = open("simple_valid.ber", O_RDONLY);
	// fd = open("minimal_valid.ber", O_RDONLY);
	map_read(fd);
	close(fd);
	return (0);
}
