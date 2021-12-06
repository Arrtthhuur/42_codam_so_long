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
	char	**map;
	size_t	nb_lines;
	size_t	len_line;
}	t_img;

// int	main(int argc, char *argv[]);
int			main(void);

/*
** Map read and check related functions.
*/
int			map_read(t_img *img);
int			check_ecp(char **map, size_t nb_lines);
int			check_len(char **map, size_t nb_lines, size_t len_line);
int			check_walls(char **map, size_t nb_lines, size_t len_line);
int			check_char(char **map, size_t nb_lines, size_t len_line);

/*
** Map building related functions.
*/
void		build_floor(t_img *img, int x, int y);
void		build_wall(t_img *img, int x, int y);
void		build_pacman(t_img *img, int x, int y);
void		build_consumable(t_img *img, int x, int y);
void		build_exit(t_img *img, int x, int y);
void		build_error(t_img *img, int x, int y);

/*
** Exit succes or error message.
*/
int			error_msg(char *msg);
int			success_msg(char *msg);

/*
** Key press related functions.
*/
// int			ft_close(int keycode, t_vars *vars);
int			key_hook(int keycode, t_img *img);

#endif