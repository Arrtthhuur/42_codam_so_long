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

static void	mlx_main(t_img *img)
{
	int		x;
	int		y;
	size_t	i;

	img->mlx = mlx_init();
	img->win = mlx_new_window(img->mlx, img->len_line * 32, \
		img->nb_lines * 32, "./so_long");
	img->img = mlx_new_image(img->mlx, img->len_line * 32, \
		img->nb_lines * 32);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
		&img->line_length, &img->endian);
	y = 0;
	while (y < img->nb_lines)
	{
		x = 0;
		while (x < img->len_line)
		{
			if (img->map[y][x] == '1')
				build_wall(img, x, y);
			else if (img->map[y][x] == '0')
				build_floor(img, x, y);
			else if (img->map[y][x] == 'C')
				build_consumable(img, x, y);
			else if (img->map[y][x] == 'E')
				build_exit(img, x, y);
			else if (img->map[y][x] == 'P')
			{
				img->beginX = x;
				img->beginY = y;
				build_pacman(img, x, y);

			}
			else
				build_error(img, x, y);
			x++;
		}
		y++;
	}
}

int	main(void)
{
	t_img	img;

	img.fd = open("map.ber", O_RDONLY);
	map_read(&img);
	mlx_main(&img);
	mlx_hook(img.win, 2, 1L<<0, key_hook, &img);
	mlx_loop(img.mlx);
	close(img.fd);
	return (EXIT_SUCCESS);
}
