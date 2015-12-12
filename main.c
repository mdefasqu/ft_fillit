/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 12:25:33 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/12/10 18:34:34 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		***final_tab;

	if (argc == 2)
	{
		if (read_file(argv, &final_tab) == 0)
			resolve(final_tab);
		else
		{
			ft_putstr("error\n");
			return (-1);
		}
	}
	return (0);
	(void)argc;
	(void)argv;
}
