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

#include <stdio.h> //printf
#include <unistd.h> //close
#include <stdlib.h> //free
#include <fcntl.h> //open

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

// static void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }

static void	mlx_main(t_img *img)
{
	int		x;
	int		y;
	size_t	i;

	img->mlx = mlx_init();
	img->win = mlx_new_window(img->mlx, 1920, 1080, "./so_long");
	img->img = mlx_new_image(img->mlx, 1920, 1080);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length,\
		&img->endian);
	y = 0;
	while (img->list->next != NULL)
	{
		if (img->list->line_nb == 0 || img->list->line_nb == img->nb_lines) 
		{
			i = 0;
			x = 0;
			while (i < img->len_line)
			{
				build_wall(img, x, y);
				x += 40;
				i++;
			}
		}
		else
		{
			i = 0;
			x = 0;
			while (i < img->len_line)
			{
				if (img->list->content[i] == '1')
					build_wall(img, x, y);
				if (img->list->content[i] == '0')
					build_floor(img, x, y);
				if (img->list->content[i] == 'P')
					build_pacman(img, x, y);
				if (img->list->content[i] == 'C')
					build_consumable(img, x, y);
				if (img->list->content[i] == 'E')
					build_exit(img, x, y);
				x += 40;
				i++;
			}
		}
		y += 40;
		img->list = img->list->next;
	}
	mlx_loop(img->mlx);
}

int	main(void)
{
	t_img	img;

	// img.fd = open("simple_valid.ber", O_RDONLY);
	img.fd = open("min_valid.ber", O_RDONLY);
	// img.fd = open("invalid.ber", O_RDONLY);
	map_read(&img);
	close(img.fd);
	mlx_main(&img);
	return (EXIT_SUCCESS);
}
