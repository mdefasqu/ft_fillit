/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 12:32:10 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/12/09 12:14:34 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	touching(char *tmp, int index)
{
	int		touch;

	touch = 0;
	tmp[index] = '.';
	if (index + 5 < 20)
	{
		if (tmp[index + 5] == '#')
			touch += touching(tmp, index + 5);
	}
	if (index - 5 > 0)
	{
		if (tmp[index - 5] == '#')
			touch += touching(tmp, index - 5);
	}
	if (index < 20 && tmp[index] != '\n')
	{
		if (index > 0 && tmp[index - 1] == '#')
			touch += touching(tmp, index - 1);
		if (tmp[index + 1] == '#')
			touch += touching(tmp, index + 1);
	}
	return (1 + touch);
}

static int	block_size(char *buf)
{
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (i < 20)
	{
		if (buf[i] == '#')
			size = touching(buf, i);
		i++;
	}
	return (size);
}

int			my_return(int size, char *buf)
{
	char	*tmp;

	if (size != 4)
		return (-1);
	tmp = ft_strdup(buf);
	size = block_size(tmp);
	ft_strdel(&tmp);
	if (size != 4)
		return (-1);
	return (0);
}

int			is_valid_tetriminos(char *buf)
{
	int		line;
	int		word;
	int		size;

	word = 0;
	line = 0;
	size = 0;
	while (line < 4)
	{
		while (word < 5)
		{
			if (buf[line * 5 + word] != '.' && buf[line * 5 + word] != '#'
				&& buf[line * 5 + word] != '\n')
				return (-1);
			if (buf[line * 5 + word] == '#')
				size++;
			word++;
		}
		if (buf[line * 5 + 4] != '\n')
			return (-1);
		line++;
		word = 0;
	}
	return (my_return(size, buf));
}
