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

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(void)
{
	int		fd;
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	fd = open("simple_valid.ber", O_RDONLY);
	// fd = open("min_valid.ber", O_RDONLY);
	// fd = open("invalid.ber", O_RDONLY);
	map_read(fd);
	close(fd);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 960, 540, "./so_long");
	img.img = mlx_new_image(mlx, 960, 540);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
		&img.line_length, &img.endian);
	my_mlx_pixel_put(&img, 50, 50, 0xFFFFFF);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
