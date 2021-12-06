/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_press.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 11:00:40 by abeznik       #+#    #+#                 */
/*   Updated: 2021/12/06 20:23:1 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**			  int
** UP 		= 126
** DOWN 	= 125
** LEFT		= 123
** RIGHT 	= 124
** ESC		= 53
*/

#include "../includes/so_long.h"

int	check_wall(t_img *img, int x, int y)
{
	if (img->map[y][x] == '1')
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	move_right(t_img *img)
{
	if (!check_wall(img, img->beginX + 1, img->beginY))
	{
		build_pacman(img, img->beginX + 1, img->beginY);
		img->beginX = img->beginX + 1;
		build_floor(img, img->beginX - 1, img->beginY);
	}
}

void	move_left(t_img *img)
{
	if (!check_wall(img, img->beginX - 1, img->beginY))
	{
		build_pacman(img, img->beginX - 1, img->beginY);
		img->beginX = img->beginX - 1;
		build_floor(img, img->beginX + 1, img->beginY);
	}
}

void	move_up(t_img *img)
{
	if (!check_wall(img, img->beginX, img->beginY - 1))
	{
		build_pacman(img, img->beginX, img->beginY - 1);
		img->beginY = img->beginY - 1;
		build_floor(img, img->beginX, img->beginY + 1);
	}
}

void	move_down(t_img *img)
{
	if (!check_wall(img, img->beginX, img->beginY + 1))
	{
		build_pacman(img, img->beginX, img->beginY + 1);
		img->beginY = img->beginY + 1;
		build_floor(img, img->beginX, img->beginY - 1);
	}
}

int	key_hook(int keycode, t_img *img)
{
	if (keycode == 53)
	{
		mlx_destroy_window(img->mlx, img->win);
		exit(EXIT_SUCCESS);
	}
	if (keycode == 124)
		move_right(img);
	if (keycode == 123)
		move_left(img);
	if (keycode == 126)
		move_up(img);
	if (keycode == 125)
		move_down(img);
	return (EXIT_SUCCESS);
}
