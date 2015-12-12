/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 12:25:33 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/12/08 18:26:55 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		if_condition_1(int i, int len, int **list)
{
	if (i + list[0][0] < len && i + list[1][0] < len && i + list[2][0] < len)
	{
		return (0);
	}
	else
	{
		return (-1);
	}
}

static int		if_condition_2(int i, int p, int **list, char **tab)
{
	if ((tab[i + list[0][0]][p + list[0][1]])
		&& (tab[i + list[1][0]][p + list[1][1]])
		&& (tab[i + list[2][0]][p + list[2][1]]))
	{
		return (0);
	}
	else
	{
		return (-1);
	}
}

static int		if_condition_3(int i, int p, int **list, char **tab)
{
	if (tab[i + list[0][0]][p + list[0][1]] == '.'
		&& tab[i + list[1][0]][p + list[1][1]] == '.'
		&& tab[i + list[2][0]][p + list[2][1]] == '.')
	{
		return (0);
	}
	else
	{
		return (-1);
	}
}

static int		if_conditions(int *mark, int **list, char **tab, int index)
{
	if (if_condition_2(mark[0], mark[1], list, tab) == 0)
	{
		if (if_condition_3(mark[0], mark[1], list, tab) == 0)
		{
			tab[mark[0]][mark[1]] = index + 64;
			tab[mark[0] + list[0][0]][mark[1] + list[0][1]] = index + 64;
			tab[mark[0] + list[1][0]][mark[1] + list[1][1]] = index + 64;
			tab[mark[0] + list[2][0]][mark[1] + list[2][1]] = index + 64;
			return (0);
		}
	}
	return (-1);
}

int				place(int **list, char **tab, int index)
{
	int		mark[2];
	int		len;

	mark[0] = 0;
	len = ft_strlen(tab[0]);
	while (mark[0] < len)
	{
		mark[1] = 0;
		while (mark[1] < len)
		{
			if (tab[mark[0]][mark[1]] == '.')
			{
				if (if_condition_1(mark[0], len, list) == 0)
				{
					if (if_conditions(mark, list, tab, index) == 0)
						return (0);
				}
			}
			mark[1]++;
		}
		mark[0]++;
	}
	return (-1);
}
