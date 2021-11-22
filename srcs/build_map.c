/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   build_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/19 16:13:31 by abeznik       #+#    #+#                 */
/*   Updated: 2021/11/22 18:04:15 by abeznik       ########   odam.nl         */
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

	img->img = mlx_png_file_to_image(img->mlx, "./images/png/small_pill.png", \
		&img_width, &img_height);
	mlx_put_image_to_window(img->mlx, img->win, img->img, x, y);
}

void	build_wall(t_img *img, int x, int y)
{
	int		img_width;
	int		img_height;

	img->img = mlx_png_file_to_image(img->mlx, "./images/png/wall.png", \
		&img_width, &img_height);
	mlx_put_image_to_window(img->mlx, img->win, img->img, x, y);
}

void	build_pacman(t_img *img, int x, int y)
{
	int		img_width;
	int		img_height;

	img->img = mlx_png_file_to_image(img->mlx, "./images/png/pacman.png", \
		&img_width, &img_height);
	mlx_put_image_to_window(img->mlx, img->win, img->img, x, y);
}

void	build_consumable(t_img *img, int x, int y)
{
	int		img_width;
	int		img_height;

	img->img = mlx_png_file_to_image(img->mlx, "./images/png/big_pill.png", \
		&img_width, &img_height);
	mlx_put_image_to_window(img->mlx, img->win, img->img, x, y);
}

void	build_exit(t_img *img, int x, int y)
{
	int		img_width;
	int		img_height;

	img->img = mlx_png_file_to_image(img->mlx, "./images/png/big_pill.png", \
		&img_width, &img_height);
	mlx_put_image_to_window(img->mlx, img->win, img->img, x, y);
}

void	build_error(t_img *img, int x, int y)
{
	int		img_width;
	int		img_height;

	img->img = mlx_png_file_to_image(img->mlx, "./images/png/error.png", \
		&img_width, &img_height);
	mlx_put_image_to_window(img->mlx, img->win, img->img, x, y);
}

/*
** XPM related functions
*/

// void	build_floor(t_img *img, int x, int y)
// {
// 	int		img_width;
// 	int		img_height;

// 	img->img = mlx_xpm_file_to_image(img->mlx, "./images/xpm/floor.xpm", \
// 		&img_width, &img_height);
// 	mlx_put_image_to_window(img->mlx, img->win, img->img, x, y);
// }

// void	build_wall(t_img *img, int x, int y)
// {
// 	int		img_width;
// 	int		img_height;

// 	img->img = mlx_xpm_file_to_image(img->mlx, "./images/xpm/wall.xpm", \
// 		&img_width, &img_height);
// 	mlx_put_image_to_window(img->mlx, img->win, img->img, x, y);
// }

// void	build_pacman(t_img *img, int x, int y)
// {
// 	int		img_width;
// 	int		img_height;

// 	img->img = mlx_xpm_file_to_image(img->mlx, "./images/pacman/pacman_r.xpm", \
// 		&img_width, &img_height);
// 	mlx_put_image_to_window(img->mlx, img->win, img->img, x, y);
// }