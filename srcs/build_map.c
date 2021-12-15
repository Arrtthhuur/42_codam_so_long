/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   build_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/08 15:23:49 by abeznik       #+#    #+#                 */
/*   Updated: 2021/12/15 13:43:50 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*
** Building map, ghost, exit and initial player position.
*/
static void	build_ghost(t_img *img, int x, int y)
{
	img->ghost_x = x;
	img->ghost_y = y;
	build_image("./images/xpm/ghost.xpm", img, x, y);
}

static void	build_hidden_exit(t_img *img, int x, int y)
{
	img->exit_x = x;
	img->exit_y = y;
	build_image("./images/xpm/pill.xpm", img, x, y);
}

static void	build_initial_pacman(t_img *img, int x, int y)
{
	img->begin_x = x;
	img->begin_y = y;
	build_image("./images/xpm/pacman_right.xpm", img, x, y);
}

void	build_map(t_img *img, int y, int x)
{
	while (y < img->nb_lines)
	{
		x = 0;
		while (x < img->len_line)
		{
			if (img->map[y][x] == '1')
				build_image("./images/xpm/wall.xpm", img, x, y);
			else if (img->map[y][x] == '0')
				build_image("./images/xpm/pill.xpm", img, x, y);
			else if (img->map[y][x] == 'C')
				build_consumable(img, x, y);
			else if (img->map[y][x] == 'G')
				build_ghost(img, x, y);
			else if (img->map[y][x] == 'E')
				build_hidden_exit(img, x, y);
			else if (img->map[y][x] == 'P')
				build_initial_pacman(img, x, y);
			else
				build_image("./images/xpm/error.xpm", img, x, y);
			x++;
		}
		y++;
	}
}
