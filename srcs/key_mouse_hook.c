/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_mouse_hook.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/11 17:00:47 by abeznik       #+#    #+#                 */
/*   Updated: 2021/12/15 13:42:26 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

#include <stdlib.h> // EXIT_

/*
** Function related to key presses.
*/
int	key_hook(int keycode, t_img *img)
{
	if (keycode == 53)
	{
		system("leaks so_long");
		mlx_destroy_window(img->mlx, img->win);
		exit(EXIT_SUCCESS);
	}
	if (keycode == 124 || keycode == 2)
		move_right(img, img->begin_x, img->begin_y);
	if (keycode == 123 || keycode == 0)
		move_left(img, img->begin_x, img->begin_y);
	if (keycode == 126 || keycode == 13)
		move_up(img, img->begin_x, img->begin_y);
	if (keycode == 125 || keycode == 1)
		move_down(img, img->begin_x, img->begin_y);
	return (EXIT_SUCCESS);
}
