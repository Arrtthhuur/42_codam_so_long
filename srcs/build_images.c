/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   build_images.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/19 16:13:31 by abeznik       #+#    #+#                 */
/*   Updated: 2021/12/11 13:45:40 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*
** XPM related functions.
*/
void	build_image(char *path, t_img *img, int x, int y)
{
	int		img_width;
	int		img_height;

	img->img = mlx_xpm_file_to_image(img->mlx, path, &img_width, &img_height);
	mlx_put_image_to_window(img->mlx, img->win, img->img, x * IMG_SIZE, \
		y * IMG_SIZE);
}

void	build_consumable(t_img *img, int x, int y)
{
	int		img_width;
	int		img_height;

	img->consumables += 1;
	img->img = mlx_xpm_file_to_image(img->mlx, "./images/xpm/pellet.xpm", \
		&img_width, &img_height);
	mlx_put_image_to_window(img->mlx, img->win, img->img, x * IMG_SIZE, \
		y * IMG_SIZE);
}

void	build_exit(t_img *img, int x, int y)
{
	int		img_width;
	int		img_height;

	img->openExit = 1;
	img->img = mlx_xpm_file_to_image(img->mlx, "./images/xpm/cherry.xpm", \
		&img_width, &img_height);
	mlx_put_image_to_window(img->mlx, img->win, img->img, x * IMG_SIZE, \
		y * IMG_SIZE);
}
