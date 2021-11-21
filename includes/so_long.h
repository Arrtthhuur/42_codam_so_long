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
# include "lists.h"

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
	size_t	nb_lines;
	size_t	len_line;
	t_list	*list;
}	t_img;

// int	main(int argc, char *argv[]);
int			main(void);

/*
** Map read and check related functions.
*/
int			map_read(t_img *img);
int			check_ecp(t_list *list, size_t line_nb);
int			check_len(t_list *list, size_t line_nb, size_t line_len);
int			check_walls(t_list *list, size_t line_nb, size_t line_len);
int			check_char(t_list *list, size_t line_nb, size_t line_len);

/*
** Map building related functions.
*/
void		build_floor(t_img *img, int x, int y);
void		build_wall(t_img *img, int x, int y);
void		build_pacman(t_img *img, int x, int y);
void		build_consumable(t_img *img, int x, int y);
void		build_exit(t_img *img, int x, int y);

/*
** Exit succes or error message.
*/
int			error_msg(char *msg);
int			success_msg(char *msg);

#endif