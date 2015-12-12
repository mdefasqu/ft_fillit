/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 12:25:33 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/12/10 18:35:44 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		get_tab_size(int nb_tetri)
{
	int i;

	i = 2;
	while ((i * i) < (nb_tetri * 4))
	{
		i++;
	}
	return (i);
}

int		*init_order(int size)
{
	int		*ret;
	int		i;

	i = 0;
	ret = (int*)malloc(sizeof(int) * size);
	while (i < size)
	{
		ret[i] = 0;
		i++;
	}
	return (ret);
}

char	**init_tab(int size)
{
	char	**ret;
	int		i;
	int		p;

	i = 0;
	ret = (char**)malloc(sizeof(char*) * size + 1);
	while (i < size)
	{
		p = 0;
		ret[i] = (char*)malloc(sizeof(char) * size + 1);
		while (p < size)
		{
			ret[i][p] = '.';
			p++;
		}
		ret[i][p] = '\0';
		i++;
	}
	ret[i] = NULL;
	return (ret);
}

void	resolve(int ***final_tab)
{
	int		i;
	int		*order;
	int		tab_size;
	char	**tab;

	tab_size = get_tab_size(final_tab[0][0][0]);
	i = 0;
	order = init_order(final_tab[0][0][0]);
	while (42)
	{
		tab = init_tab(tab_size + i);
		permutation(order, 0, &final_tab, tab);
		i++;
		ft_strdel_2d(&tab);
	}
}
