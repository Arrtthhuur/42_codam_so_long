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

#include "../includes/so_long.h"

/*
** Function related to key presses.
*/
int	key_hook(int keycode, t_img *img)
{
	if (keycode == 53)
	{
		mlx_destroy_window(img->mlx, img->win);
		exit(EXIT_SUCCESS);
	}
	if (keycode == 124 || keycode == 2)
		move_right(img, img->beginX, img->beginY);
	if (keycode == 123 || keycode == 0)
		move_left(img, img->beginX, img->beginY);
	if (keycode == 126 || keycode == 13)
		move_up(img, img->beginX, img->beginY);
	if (keycode == 125 || keycode == 1)
		move_down(img, img->beginX, img->beginY);
	return (EXIT_SUCCESS);
}
