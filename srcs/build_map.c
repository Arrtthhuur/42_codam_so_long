/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   build_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/19 16:13:31 by abeznik       #+#    #+#                 */
/*   Updated: 2021/12/06 19:46:40 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*
** PNG related functions.
*/
void	build_floor(t_img *img, int x, int y)
{
	int		img_width;
	int		img_height;

	img->img = mlx_png_file_to_image(img->mlx, "./images/png/pill.png", \
		&img_width, &img_height);
	mlx_put_image_to_window(img->mlx, img->win, img->img, x * 32, y * 32);
}

void	build_wall(t_img *img, int x, int y)
{
	int		img_width;
	int		img_height;

	img->img = mlx_png_file_to_image(img->mlx, "./images/png/wall.png", \
		&img_width, &img_height);
	mlx_put_image_to_window(img->mlx, img->win, img->img, x * 32, y * 32);
}

void	build_pacman(t_img *img, int x, int y)
{
	int		img_width;
	int		img_height;

	img->img = mlx_png_file_to_image(img->mlx, "./images/png/pacman.png", \
		&img_width, &img_height);
	mlx_put_image_to_window(img->mlx, img->win, img->img, x * 32, y * 32);
}

void	build_consumable(t_img *img, int x, int y)
{
	int		img_width;
	int		img_height;

	img->img = mlx_png_file_to_image(img->mlx, "./images/png/pellet.png", \
		&img_width, &img_height);
	mlx_put_image_to_window(img->mlx, img->win, img->img, x * 32, y * 32);
}

void	build_exit(t_img *img, int x, int y)
{
	int		img_width;
	int		img_height;

	img->img = mlx_png_file_to_image(img->mlx, "./images/png/cherry.png", \
		&img_width, &img_height);
	mlx_put_image_to_window(img->mlx, img->win, img->img, x * 32, y * 32);
}

void	build_error(t_img *img, int x, int y)
{
	int		img_width;
	int		img_height;

	img->img = mlx_png_file_to_image(img->mlx, "./images/png/error.png", \
		&img_width, &img_height);
	mlx_put_image_to_window(img->mlx, img->win, img->img, x * 32, y * 32);
}
