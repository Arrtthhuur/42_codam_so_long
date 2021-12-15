/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/15 09:15:26 by abeznik       #+#    #+#                 */
/*   Updated: 2021/12/13 12:38:15 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

#include <stdlib.h> // free, malloc

static char	**ft_free(int j, char **buff)
{
	int	i;

	i = 0;
	while (j >= i)
	{
		free(buff[j]);
		j--;
	}
	free(buff);
	return (NULL);
}

static int	ft_wordlength(int j, const char *s, char c)
{
	int	i;
	int	x;

	i = 0;
	while (j >= 0)
	{
		while ((s[i] == c) && (s[i] != '\0'))
			i++;
		x = i;
		while ((s[i] != c) && (s[i] != '\0'))
			i++;
		j--;
	}
	return (i - x);
}

static int	ft_wordcount(char const *s, char c, int x)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			if (x >= 0)
			{
				if (x == 0)
					return (i);
			}
			i++;
		}
		x--;
		j++;
	}
	if (s[i - 1] == c)
		j--;
	return (j);
}

char	**ft_split(char const *s, char c)
{
	char	**buff;
	int		j;

	if (s == NULL)
		return (NULL);
	buff = (char **)malloc(sizeof(char *) * (1 + ft_wordcount(s, c, -1)));
	if (buff == NULL)
		return (NULL);
	j = 0;
	while (j < ft_wordcount(s, c, -1))
	{
		buff[j] = ft_substr(s, ft_wordcount(s, c, j), ft_wordlength(j, s, c));
		if (buff[j] == NULL)
			return (ft_free(j, buff));
		j++;
	}
	buff[j] = NULL;
	return (buff);
}
