/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   build_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/19 16:13:31 by abeznik       #+#    #+#                 */
/*   Updated: 2021/11/21 18:35:28 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	build_floor(t_img *img, int x, int y)
{
	int		img_width;
	int		img_height;

	img->img = mlx_xpm_file_to_image(img->mlx, "./images/floor.xpm", \
		&img_width, &img_height);
	mlx_put_image_to_window(img->mlx, img->win, img->img, x, y);
}

void	build_wall(t_img *img, int x, int y)
{
	int		img_width;
	int		img_height;

	img->img = mlx_xpm_file_to_image(img->mlx, "./images/wall.xpm", \
		&img_width, &img_height);
	mlx_put_image_to_window(img->mlx, img->win, img->img, x, y);
}

void	build_pacman(t_img *img, int x, int y)
{
	int		img_width;
	int		img_height;

	img->img = mlx_xpm_file_to_image(img->mlx, "./images/pacman/pacman_r.xpm", \
		&img_width, &img_height);
	mlx_put_image_to_window(img->mlx, img->win, img->img, x, y);
}

void	build_consumable(t_img *img, int x, int y)
{
	int		img_width;
	int		img_height;

	img->img = mlx_xpm_file_to_image(img->mlx, "./images/consumable_bigpill.xpm", \
		&img_width, &img_height);
	mlx_put_image_to_window(img->mlx, img->win, img->img, x, y);
}

void	build_exit(t_img *img, int x, int y)
{
	int		img_width;
	int		img_height;

	img->img = mlx_xpm_file_to_image(img->mlx, "./images/exit.xpm", \
		&img_width, &img_height);
	mlx_put_image_to_window(img->mlx, img->win, img->img, x, y);
}
