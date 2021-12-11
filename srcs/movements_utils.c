/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   movements_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/08 13:33:38 by abeznik       #+#    #+#                 */
/*   Updated: 2021/12/11 13:32:53 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdio.h> // printf

/*
** Utilitary functions related to movements.
*/
int	check_ifWall(t_img *img, int x, int y)
{
	if (img->map[y][x] == '1')
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	check_ifExit(t_img *img, int x, int y)
{
	if (img->map[y][x] == 'E' && img->openExit == 1)
	{
		printf("YOU WON!\n\tYour score is %d\n", img->mov_count);
		printf("\tHigh Score is 999985641351\n");
		exit(0);
	}
}

void	check_ifContact(int x, int y, int ghostX, int ghostY)
{
	if (x == ghostX && y == ghostY)
	{
		printf("YOU LOST!\n\tYour score is -1\n");
		printf("\tHigh Score is 999985641351\n");
		exit(0);
	}
}

void	consumable_count(t_img *img, int x, int y)
{
	if (img->map[y][x] == 'C')
	{
		img->consumables -= 1;
		img->map[y][x] = '0';
		printf("\tConsumables left: %zu\n", img->consumables);
	}
}

void	movement_count(t_img *img)
{
	img->mov_count += 1;
	printf("Current nb of moves: %d\n", img->mov_count);
	img->count = ft_utoa(img->mov_count);
	if (!img->count)
		exit(EXIT_FAILURE);
	build_image("./images/xpm/scoreboard.xpm", img, 0, 0);
	build_image("./images/xpm/scoreboard.xpm", img, 1, 0);
	mlx_string_put(img->mlx, img->win, 5, 20, 0, img->count);
	free(img->count);
}
