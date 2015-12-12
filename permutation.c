/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 17:34:22 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/12/10 18:40:27 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		resovle_finish(char **tab, int **order, int ****list)
{
	ft_intdel(order);
	free_final_tab(list, (*list)[0][0][0]);
	ft_strdel_2d(&tab);
	exit(0);
}

void			permutation(int *order, int k, int ****list, char **tab)
{
	static int	level = -1;
	int			i;

	i = 0;
	level = level + 1;
	order[k] = level;
	if (level == (*list)[0][0][0])
	{
		if (fill_tab((*list), order, tab) == 0)
			resovle_finish(tab, &order, list);
	}
	else
	{
		while (i < (*list)[0][0][0])
		{
			if (order[i] == 0)
				permutation(order, i, list, tab);
			i++;
		}
	}
	level = level - 1;
	order[k] = 0;
}
