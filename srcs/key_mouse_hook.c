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
