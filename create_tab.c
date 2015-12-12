/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 14:59:22 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/12/10 18:56:33 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		check_next(int i, int ***pos, int *tab)
{
	if (i - 1 >= 0)
	{
		(*pos)[i][0] = 1 + (*pos)[i - 1][0];
		(*pos)[i][1] = ((tab[i + 1] - tab[0]) -
			(5 * (*pos)[i][0]));
	}
	else
	{
		(*pos)[i][0] = 1;
		(*pos)[i][1] = ((tab[i + 1] - tab[0]) -
			(5 * (*pos)[i][0]));
	}
}

static void		check_first(int i, int ***pos)
{
	if (i - 1 >= 0)
	{
		(*pos)[i][0] = 0 + (*pos)[i - 1][0];
		(*pos)[i][1] = 1 + (*pos)[i - 1][1];
	}
	else
	{
		(*pos)[i][0] = 0;
		(*pos)[i][1] = 1;
	}
}

static void		make_tab(int ***pos, int *tab)
{
	int i;

	i = 0;
	while (i < 3)
	{
		if (tab[i] == (tab[i + 1] - 1))
			check_first(i, pos);
		else
			check_next(i, pos, tab);
		i++;
	}
}

int				**create_form(const char *buf)
{
	int		**pos;
	int		i;
	int		tab[4];
	int		y;

	y = 0;
	i = 0;
	pos = (int **)malloc(sizeof(int *) * 3);
	while (i < 3)
	{
		pos[i] = (int *)malloc(sizeof(int) * 2);
		i++;
	}
	i = 0;
	while (i < 20)
	{
		if (buf[i] == '#')
		{
			tab[y] = i;
			y++;
		}
		i++;
	}
	make_tab(&pos, tab);
	return (pos);
}
