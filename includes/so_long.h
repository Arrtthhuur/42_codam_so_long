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

#ifndef SOLONG_H
# define SOLONG_H

# include "../mlx/mlx.h"
# include "get_next_line.h"
# include "lists.h"
# include "libft.h"

// int	main(int argc, char *argv[]);
int	main(void);

/*
** Map related functions.
*/
int	map_read(int fd);

#endif