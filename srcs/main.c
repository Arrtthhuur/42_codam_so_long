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

int	main(int argc, char *argv[])
{
	// char	*file_name;
	int		fd;

	// printf("This program was called with \"%s\".\n", argv[0]);
	// if (argc == 1)
	// {
	// 	count = 1;
	// 	while (count < argc)
	// 	{
	// 		printf("argv[%d] = %s\n", count, argv[count]);
	// 		count++;
	// 	}
	// }
	// else
	// {
	// 	printf("The command had no others arguments.\n");
	// }

	// file_name = "../maps/simple_valid.ber";
	if (argc < 1)
	{
		printf("Error\nNo map entered!");
	}
	else
	{
		printf("%s\n", argv[1]);
		fd = open(argv[1], O_RDONLY);
		so_long(fd);
		close(fd);
	}
	return (0);
}