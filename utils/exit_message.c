/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit_message.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/08 15:57:26 by abeznik       #+#    #+#                 */
/*   Updated: 2021/12/13 12:37:54 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

#include <stdlib.h> // EXIT_
#include <unistd.h> // write

int	error_msg(char *msg)
{
	write(2, "Error\n", 7);
	if (msg)
		write(2, msg, ft_strlen(msg));
	return (EXIT_FAILURE);
}

int	success_msg(char *msg)
{
	write(2, "Success\n", 9);
	if (msg)
		write(2, msg, ft_strlen(msg));
	return (EXIT_SUCCESS);
}
