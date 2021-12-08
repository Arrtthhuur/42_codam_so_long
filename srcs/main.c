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

static int	ft_close(void)
{
	exit(EXIT_SUCCESS);
}

static void	mlx_main(t_img *img)
{
	int	sizey;
	int	sizex;

	img->mlx = mlx_init();
	img->win = mlx_new_window(img->mlx, img->len_line * IMG_SIZE, \
		img->nb_lines * IMG_SIZE, "./so_long");
	img->img = mlx_new_image(img->mlx, img->len_line * IMG_SIZE, \
		img->nb_lines * IMG_SIZE);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
		&img->line_length, &img->endian);
	mlx_get_screen_size(img->mlx, &sizex, &sizey);
	if (img->len_line * IMG_SIZE > sizex || img->nb_lines * IMG_SIZE > sizey)
	{
		error_msg("\tMap too big for screen.\n");
		exit(EXIT_FAILURE);
	}
	img->consumables = 0;
	img->openExit = 0;
	build_map(img, 0, 0);
}

int	main(int argc, char **argv)
{
	t_img	img;

	if (argc < 2)
		return (error_msg("\tNo map entered.\n"));
	img.fd = open(argv[1], O_RDONLY);
	map_read(&img);
	mlx_main(&img);
	mlx_hook(img.win, 2, 1L << 0, key_hook, &img);
	mlx_hook(img.win, 17, 1L << 17, ft_close, &img);
	mlx_loop(img.mlx);
	close(img.fd);
	return (EXIT_SUCCESS);
}
