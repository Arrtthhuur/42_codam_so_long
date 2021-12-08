/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   movements.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/08 13:33:38 by abeznik       #+#    #+#                 */
/*   Updated: 2021/12/08 17:31:48 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdio.h> // printf

void	move_right(t_img *img)
{
	if (!check_ifWall(img, img->beginX + 1, img->beginY))
	{
		consumable_count(img, img->beginY, img->beginX + 1);
		if (img->consumables == 0 && img->openExit == 0)
			build_exit(img, img->exitX, img->exitY);
		build_image("./images/xpm/pacman.xpm", img, img->beginX + 1, \
			img->beginY);
		check_ifContact(img->beginX + 1, img->beginY, img->ghostX, \
			img->ghostY);
		check_ifExit(img, img->beginX + 1, img->beginY);
		img->beginX = img->beginX + 1;
		build_image("./images/xpm/pill.xpm", img, img->beginX - 1, \
			img->beginY);
		movement_count(img);
	}
	ghost_move_left(img);
}

void	move_left(t_img *img)
{
	if (!check_ifWall(img, img->beginX - 1, img->beginY))
	{
		consumable_count(img, img->beginY, img->beginX - 1);
		if (img->consumables == 0 && img->openExit == 0)
			build_exit(img, img->exitX, img->exitY);
		build_image("./images/xpm/pacman.xpm", img, img->beginX - 1, \
			img->beginY);
		check_ifContact(img->beginX - 1, img->beginY, img->ghostX, \
			img->ghostY);
		check_ifExit(img, img->beginX - 1, img->beginY);
		img->beginX = img->beginX - 1;
		build_image("./images/xpm/pill.xpm", img, img->beginX + 1, \
			img->beginY);
		movement_count(img);
	}
	ghost_move_right(img);
}

void	move_up(t_img *img)
{
	if (!check_ifWall(img, img->beginX, img->beginY - 1))
	{
		consumable_count(img, img->beginY - 1, img->beginX);
		if (img->consumables == 0 && img->openExit == 0)
			build_exit(img, img->exitX, img->exitY);
		build_image("./images/xpm/pacman.xpm", img, img->beginX, \
			img->beginY - 1);
		check_ifContact(img->beginX, img->beginY - 1, img->ghostX, \
			img->ghostY);
		check_ifExit(img, img->beginX, img->beginY - 1);
		img->beginY = img->beginY - 1;
		build_image("./images/xpm/pill.xpm", img, img->beginX, \
			img->beginY + 1);
		movement_count(img);
	}
	ghost_move_down(img);
}

void	move_down(t_img *img)
{
	if (!check_ifWall(img, img->beginX, img->beginY + 1))
	{
		consumable_count(img, img->beginY + 1, img->beginX);
		if (img->consumables == 0 && img->openExit == 0)
			build_exit(img, img->exitX, img->exitY);
		build_image("./images/xpm/pacman.xpm", img, img->beginX, \
			img->beginY + 1);
		check_ifContact(img->beginX, img->beginY + 1, img->ghostX, \
			img->ghostY);
		check_ifExit(img, img->beginX, img->beginY + 1);
		img->beginY = img->beginY + 1;
		build_image("./images/xpm/pill.xpm", img, img->beginX, \
			img->beginY - 1);
		movement_count(img);
	}
	ghost_move_up(img);
}
