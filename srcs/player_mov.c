/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_mov.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/08 13:33:38 by abeznik       #+#    #+#                 */
/*   Updated: 2021/12/11 13:11:44 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*
** Player movements related functions.
*/
void	move_right(t_img *img, int x, int y)
{
	if (!check_ifWall(img, x + 1, y))
	{
		consumable_count(img, x + 1, y);
		if (img->consumables == 0 && img->openExit == 0)
			build_exit(img, img->exitX, img->exitY);
		build_image("./images/xpm/pacman_right.xpm", img, x + 1, y);
		check_ifExit(img, x + 1, y);
		img->beginX = img->beginX + 1;
		build_image("./images/xpm/pill.xpm", img, x, y);
		movement_count(img);
	}
	ghost_move_left(img, img->ghostX, img->ghostY);
	check_ifContact(x + 1, y, img->ghostX, img->ghostY);
}

void	move_left(t_img *img, int x, int y)
{
	if (!check_ifWall(img, x - 1, y))
	{
		consumable_count(img, x - 1, y);
		if (img->consumables == 0 && img->openExit == 0)
			build_exit(img, img->exitX, img->exitY);
		build_image("./images/xpm/pacman_left.xpm", img, x - 1, y);
		check_ifExit(img, x - 1, y);
		img->beginX = img->beginX - 1;
		build_image("./images/xpm/pill.xpm", img, x, y);
		movement_count(img);
	}
	ghost_move_right(img, img->ghostX, img->ghostY);
	check_ifContact(x - 1, y, img->ghostX, img->ghostY);
}

void	move_up(t_img *img, int x, int y)
{
	if (!check_ifWall(img, x, y - 1))
	{
		consumable_count(img, x, y - 1);
		if (img->consumables == 0 && img->openExit == 0)
			build_exit(img, img->exitX, img->exitY);
		build_image("./images/xpm/pacman_up.xpm", img, x, y - 1);
		check_ifExit(img, x, y - 1);
		img->beginY = img->beginY - 1;
		build_image("./images/xpm/pill.xpm", img, x, y);
		movement_count(img);
	}
	ghost_move_down(img, img->ghostX, img->ghostY);
	check_ifContact(x, y - 1, img->ghostX, img->ghostY);
}

void	move_down(t_img *img, int x, int y)
{
	if (!check_ifWall(img, x, y + 1))
	{
		consumable_count(img, x, y + 1);
		if (img->consumables == 0 && img->openExit == 0)
			build_exit(img, img->exitX, img->exitY);
		build_image("./images/xpm/pacman_down.xpm", img, x, y + 1);
		check_ifExit(img, x, y + 1);
		img->beginY = img->beginY + 1;
		build_image("./images/xpm/pill.xpm", img, x, y);
		movement_count(img);
	}
	ghost_move_up(img, img->ghostX, img->ghostY);
	check_ifContact(x, y + 1, img->ghostX, img->ghostY);
}
