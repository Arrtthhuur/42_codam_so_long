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

static void	midLines(t_img *img, int y)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (i < img->len_line)
	{
		if (img->list->content[i] == '1')
		{
			img->map[img->list->line_nb][x/32] = img->list->content[i];
			build_wall(img, x, y);
		}
		else if (img->list->content[i] == '0')
		{
			img->map[img->list->line_nb][x/32] = img->list->content[i];
			build_floor(img, x, y);
		}
		else if (img->list->content[i] == 'C')
		{
			img->map[img->list->line_nb][x/32] = img->list->content[i];
			build_consumable(img, x, y);
		}
		else if (img->list->content[i] == 'E')
		{
			img->map[img->list->line_nb][x/32] = img->list->content[i];
			build_exit(img, x, y);
		}
		else if (img->list->content[i] == 'P')
		{
			img->beginX = x;
			img->beginY = y;
			img->map[img->list->line_nb][x/32] = img->list->content[i];
			build_pacman(img, x, y);
		}
		else
			build_error(img, x, y);
		x += 32;
		i++;
	}
}

static void	first_lastLines(t_img *img, int y)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (i < img->len_line)
	{
		if (img->list->content[i] == '1')
		{
			build_wall(img, x, y);
			img->map[img->list->line_nb][x/32] = img->list->content[i];
		}
		else
			build_error(img, x, y);
		x += 32;
		i++;
	}
}

static void	mlx_alloc(t_img *img)
{
	int	y;
	int	i;
	y = 0;
	i = 0;
	while (y < 10)
	{
		i = 0;
		while (i <10)
		{
			img->map[y][i] = '\0';
			i++;
		}
		y++;
	}
}

static void	mlx_main(t_img *img)
{
	int		x;
	int		y;
	int		nb_line;
	size_t	i;

	nb_line = img->nb_lines + 1;
	img->mlx = mlx_init();
	img->win = mlx_new_window(img->mlx, img->len_line * 32, nb_line * 32, "./so_long");
	img->img = mlx_new_image(img->mlx, img->len_line * 32, nb_line * 32);
	// img->win = mlx_new_window(img->mlx, 34, 34, "./so_long");
	// img->img = mlx_new_image(img->mlx, 34, 34);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
		&img->line_length, &img->endian);
	mlx_alloc(img);
	y = 0;
	while (img->list->next != NULL)
	{
		if (img->list->line_nb == 0 || img->list->line_nb == img->nb_lines)
			first_lastLines(img, y);
		else
			midLines(img, y);
		y += 32;
		img->list = img->list->next;
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
