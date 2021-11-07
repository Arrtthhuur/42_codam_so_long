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

// int	main(int argc, char *argv[]);
int		main(void);

/*
** Map read and check related functions.
*/
int		map_read(int fd);
int		check_ecp(t_list *list, size_t line_nb);
int		check_len(t_list *list, size_t line_nb, size_t line_len);
int		check_walls(t_list *list, size_t line_nb, size_t line_len);

#endif