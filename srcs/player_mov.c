/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_mov.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/08 13:33:38 by abeznik       #+#    #+#                 */
/*   Updated: 2021/12/18 13:20:50 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

#include <stdlib.h> // rand

/*
** Player movements related functions.
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

void	move_right(t_img *img, int x, int y)
{
	if (!check_if_wall(img, x + 1, y))
	{
		consumable_count(img, x + 1, y);
		if (img->consumables == 0 && img->open_exit == 0)
			build_exit(img, img->exit_x, img->exit_y);
		build_image("./images/xpm/pacman_right.xpm", img, x + 1, y);
		check_if_exit(img, x + 1, y);
		img->begin_x = img->begin_x + 1;
		build_image("./images/xpm/pill.xpm", img, x, y);
		movement_count(img);
	}
	random_ghost_move(img, img->ghost_x, img->ghost_y);
	check_if_contact(img->begin_x, img->begin_y, img->ghost_x, img->ghost_y);
}

void	move_left(t_img *img, int x, int y)
{
	if (!check_if_wall(img, x - 1, y))
	{
		consumable_count(img, x - 1, y);
		if (img->consumables == 0 && img->open_exit == 0)
			build_exit(img, img->exit_x, img->exit_y);
		build_image("./images/xpm/pacman_left.xpm", img, x - 1, y);
		check_if_exit(img, x - 1, y);
		img->begin_x = img->begin_x - 1;
		build_image("./images/xpm/pill.xpm", img, x, y);
		movement_count(img);
	}
	random_ghost_move(img, img->ghost_x, img->ghost_y);
	check_if_contact(img->begin_x, img->begin_y, img->ghost_x, img->ghost_y);
}

void	move_up(t_img *img, int x, int y)
{
	if (!check_if_wall(img, x, y - 1))
	{
		consumable_count(img, x, y - 1);
		if (img->consumables == 0 && img->open_exit == 0)
			build_exit(img, img->exit_x, img->exit_y);
		build_image("./images/xpm/pacman_up.xpm", img, x, y - 1);
		check_if_exit(img, x, y - 1);
		img->begin_y = img->begin_y - 1;
		build_image("./images/xpm/pill.xpm", img, x, y);
		movement_count(img);
	}
	random_ghost_move(img, img->ghost_x, img->ghost_y);
	check_if_contact(img->begin_x, img->begin_y, img->ghost_x, img->ghost_y);
}

void	move_down(t_img *img, int x, int y)
{
	if (!check_if_wall(img, x, y + 1))
	{
		consumable_count(img, x, y + 1);
		if (img->consumables == 0 && img->open_exit == 0)
			build_exit(img, img->exit_x, img->exit_y);
		build_image("./images/xpm/pacman_down.xpm", img, x, y + 1);
		check_if_exit(img, x, y + 1);
		img->begin_y = img->begin_y + 1;
		build_image("./images/xpm/pill.xpm", img, x, y);
		movement_count(img);
	}
	random_ghost_move(img, img->ghost_x, img->ghost_y);
	check_if_contact(img->begin_x, img->begin_y, img->ghost_x, img->ghost_y);
}
