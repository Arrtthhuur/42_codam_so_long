/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/21 21:21:21 by abeznik       #+#    #+#                 */
/*   Updated: 2021/10/21 21:21:21 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "get_next_line.h"

# include <stdlib.h> //EXIT_
# include <unistd.h> //write


# define IMG_SIZE 31

typedef struct s_img
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		fd;
	int		beginX;
	int		beginY;
	int		exitX;
	int		exitY;
	int		openExit;
	int		ghostX;
	int		ghostY;
	char	**map;
	int		mov_count;
	char	*count;
	int		nb_lines;
	int		len_line;
	size_t	consumables;
}	t_img;

int	main(int argc, char **argv);

/*
** Map read and check related functions.
*/
int			map_read(t_img *img);
int			check_ecp(char **map, int nb_lines);
int			check_len(char **map, int nb_lines, int len_line);
int			check_walls(char **map, int nb_lines, int len_line);
int			check_char(char **map, int nb_lines, int len_line);

/*
** Map building related functions.
*/
void		build_map(t_img *img, int y, int x);
void		build_image(char *path, t_img *img, int x, int y);
void		build_consumable(t_img *img, int x, int y);
void		build_exit(t_img *img, int x, int y);

/*
** Player movement related functions.
*/
void		move_right(t_img *img);
void		move_left(t_img *img);
void		move_up(t_img *img);
void		move_down(t_img *img);
int			check_ifWall(t_img *img, int x, int y);
void		movement_count(t_img *img);
void		consumable_count(t_img *img, int y, int x);
void		check_ifExit(t_img *img, int x, int y);
void		check_ifContact(int beginX, int beginY, \
			int ghostX, int ghostY);
/*
** Ghost movement related functions.
*/
void		ghost_move_right(t_img *img);
void		ghost_move_left(t_img *img);
void		ghost_move_up(t_img *img);
void		ghost_move_down(t_img *img);
/*
** Exit succes or error message.
*/
int			error_msg(char *msg);
int			success_msg(char *msg);

/*
** Key/mouse press related functions.
*/
int			key_hook(int keycode, t_img *img);

/*
** Misc.
*/
char		*ft_utoa(unsigned int ui);

#endif