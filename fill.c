/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 12:25:33 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/12/10 18:41:09 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		print_resolve(char **tab)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(tab[0]);
	while (i < len)
	{
		ft_putstr(tab[i]);
		ft_putchar('\n');
		i++;
	}
}

static void		clean_tab(char **tab)
{
	int		i;
	int		p;
	int		len;

	i = 0;
	p = 0;
	len = ft_strlen(tab[0]);
	while (i < len)
	{
		while (p < len)
		{
			tab[i][p] = '.';
			p++;
		}
		p = 0;
		i++;
	}
}

int				fill_tab(int ***list, int *order, char **tab)
{
	int			i;

	i = 0;
	while (i < list[0][0][0])
	{
		if (place(list[order[i]], tab, order[i]) == 0)
		{
			i++;
		}
		else
		{
			clean_tab(tab);
			return (-1);
		}
	}
	print_resolve(tab);
	return (0);
}
