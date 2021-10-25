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

# include "get_next_line.h"
# include "lists.h"

// int	main(int argc, char *argv[]);

int	main(void);

int	so_long(int fd, int fd_copy);

int map_check(int fd, int fd_copy);

#endif