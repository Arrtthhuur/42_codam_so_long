/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/16 12:41:32 by abeznik       #+#    #+#                 */
/*   Updated: 2021/11/07 17:40:40 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h> // size_t

# define MAX_FD 1024
# define BUFFER_SIZE 1

char	*get_next_line(int fd);

size_t	ft_strlen(const char *s);

char	*ft_strdup(const char *s1);

char	*ft_strchr(const char *s, int c);

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif