/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ghost_mov.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/08 13:33:38 by abeznik       #+#    #+#                 */
/*   Updated: 2021/12/18 13:18:03 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*
** Functions related to ghost movements.
*/
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
}
