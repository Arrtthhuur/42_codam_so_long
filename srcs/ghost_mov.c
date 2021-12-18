/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ghost_mov.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/08 13:33:38 by abeznik       #+#    #+#                 */
/*   Updated: 2021/12/18 16:34:11 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

#include <stdlib.h> // rand

/*
** Functions related to ghost movements.
*/
void	random_ghost_move(t_img *img, int x, int y)
{
	int	r;

	r = 0;
	r = rand() % 4;
	if (r == 0)
		ghost_move_left(img, x, y);
	if (r == 1)
		ghost_move_right(img, x, y);
	if (r == 2)
		ghost_move_up(img, x, y);
	if (r == 3)
		ghost_move_down(img, x, y);
}

void	ghost_move_right(t_img *img, int x, int y)
{
	if (!check_if_wall(img, x + 1, y))
	{
		build_image("./images/xpm/ghost.xpm", img, x + 1, y);
		if (img->map[y][x] == 'C')
			build_image("./images/xpm/pellet.xpm", img, x, y);
		else if (img->map[y][x] == 'E' && img->open_exit == 1)
			build_image("./images/xpm/cherry.xpm", img, x, y);
		else
			build_image("./images/xpm/pill.xpm", img, x, y);
		img->ghost_x = img->ghost_x + 1;
	}
	else
		random_ghost_move(img, img->ghost_x, img->ghost_y);
}

void	ghost_move_left(t_img *img, int x, int y)
{
	if (!check_if_wall(img, x - 1, y))
	{
		build_image("./images/xpm/ghost.xpm", img, x - 1, y);
		if (img->map[y][x] == 'C')
			build_image("./images/xpm/pellet.xpm", img, x, y);
		else if (img->map[y][x] == 'E' && img->open_exit == 1)
			build_image("./images/xpm/cherry.xpm", img, x, y);
		else
			build_image("./images/xpm/pill.xpm", img, x, y);
		img->ghost_x = img->ghost_x - 1;
	}
	else
		random_ghost_move(img, img->ghost_x, img->ghost_y);
}

void	ghost_move_up(t_img *img, int x, int y)
{
	if (!check_if_wall(img, x, y - 1))
	{
		build_image("./images/xpm/ghost.xpm", img, x, y - 1);
		if (img->map[y][x] == 'C')
			build_image("./images/xpm/pellet.xpm", img, x, y);
		else if (img->map[y][x] == 'E' && img->open_exit == 1)
			build_image("./images/xpm/cherry.xpm", img, x, y);
		else
			build_image("./images/xpm/pill.xpm", img, x, y);
		img->ghost_y = img->ghost_y - 1;
	}
	else
		random_ghost_move(img, img->ghost_x, img->ghost_y);
}

void	ghost_move_down(t_img *img, int x, int y)
{
	if (!check_if_wall(img, x, y + 1))
	{
		build_image("./images/xpm/ghost.xpm", img, x, y + 1);
		if (img->map[y][x] == 'C')
			build_image("./images/xpm/pellet.xpm", img, x, y);
		else if (img->map[y][x] == 'E' && img->open_exit == 1)
			build_image("./images/xpm/cherry.xpm", img, x, y);
		else
			build_image("./images/xpm/pill.xpm", img, x, y);
		img->ghost_y = img->ghost_y + 1;
	}
	else
		random_ghost_move(img, img->ghost_x, img->ghost_y);
}
