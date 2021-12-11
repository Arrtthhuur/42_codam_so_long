/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ghost_mov.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/08 13:33:38 by abeznik       #+#    #+#                 */
/*   Updated: 2021/12/11 13:43:42 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*
** Functions related to ghost movements.
*/
void	ghost_move_right(t_img *img, int x, int y)
{
	if (!check_ifWall(img, x + 1, y))
	{
		build_image("./images/xpm/ghost.xpm", img, x + 1, y);
		if (img->map[y][x] == 'C')
			build_image("./images/xpm/pellet.xpm", img, x, y);
		else if (img->map[y][x] == 'E' && img->openExit == 1)
			build_image("./images/xpm/cherry.xpm", img, x, y);
		else
			build_image("./images/xpm/pill.xpm", img, x, y);
		img->ghostX = img->ghostX + 1;
	}
	else if (!check_ifWall(img, x - 1, y))
		ghost_move_left(img, img->ghostX, img->ghostY);
}

void	ghost_move_left(t_img *img, int x, int y)
{
	if (!check_ifWall(img, x - 1, y))
	{
		build_image("./images/xpm/ghost.xpm", img, x - 1, y);
		if (img->map[y][x] == 'C')
			build_image("./images/xpm/pellet.xpm", img, x, y);
		else if (img->map[y][x] == 'E' && img->openExit == 1)
			build_image("./images/xpm/cherry.xpm", img, x, y);
		else
			build_image("./images/xpm/pill.xpm", img, x, y);
		img->ghostX = img->ghostX - 1;
	}
	else if (!check_ifWall(img, x + 1, y))
		ghost_move_right(img, img->ghostX, img->ghostY);
}

void	ghost_move_up(t_img *img, int x, int y)
{
	if (!check_ifWall(img, x, y - 1))
	{
		build_image("./images/xpm/ghost.xpm", img, x, y - 1);
		if (img->map[y][x] == 'C')
			build_image("./images/xpm/pellet.xpm", img, x, y);
		else if (img->map[y][x] == 'E' && img->openExit == 1)
			build_image("./images/xpm/cherry.xpm", img, x, y);
		else
			build_image("./images/xpm/pill.xpm", img, x, y);
		img->ghostY = img->ghostY - 1;
	}
	else if (!check_ifWall(img, x, y + 1))
		ghost_move_down(img, img->ghostX, img->ghostY);
}

void	ghost_move_down(t_img *img, int x, int y)
{
	if (!check_ifWall(img, x, y + 1))
	{
		build_image("./images/xpm/ghost.xpm", img, x, y + 1);
		if (img->map[y][x] == 'C')
			build_image("./images/xpm/pellet.xpm", img, x, y);
		else if (img->map[y][x] == 'E' && img->openExit == 1)
			build_image("./images/xpm/cherry.xpm", img, x, y);
		else
			build_image("./images/xpm/pill.xpm", img, x, y);
		img->ghostY = img->ghostY + 1;
	}
	else if (!check_ifWall(img, x, y - 1))
		ghost_move_up(img, img->ghostX, img->ghostY);
}
