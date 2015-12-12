/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 12:25:20 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/12/10 18:54:49 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	make_3d_int(int ****tmp_tab)
{
	*tmp_tab = (int ***)malloc(sizeof(int **) * 27);
	(*tmp_tab)[0] = (int **)malloc(sizeof(int *) * 1);
	(*tmp_tab)[0][0] = (int *)malloc(sizeof(int) * 1);
	(*tmp_tab)[0][0][0] = 0;
}

static int	error_in_parsing(char **buf)
{
	ft_strdel(buf);
	return (-1);
}

static int	read_tetriminos(char *buf, int *fd)
{
	if (read(*fd, buf, 20) < 20)
		return (-1);
	if (is_valid_tetriminos(buf) < 0)
		return (-1);
	return (0);
}

static int	read_empty_line(char *buf, int *fd)
{
	if (read(*fd, buf, 1) <= 0)
		return (1);
	if (buf[0] != '\n')
		return (-1);
	return (0);
}

int			read_file(char **argv, int ****tmp_tab)
{
	int		fd;
	char	*buf;
	int		newline;
	int		nb_tetri;

	nb_tetri = 0;
	buf = ft_strnew(21);
	make_3d_int(tmp_tab);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (error_in_parsing(&buf));
	while (42)
	{
		if (read_tetriminos(buf, &fd) < 0)
			return (error_in_parsing(&buf));
		(*tmp_tab)[nb_tetri + 1] = create_form(buf);
		newline = read_empty_line(buf, &fd);
		nb_tetri++;
		if (newline < 0 || nb_tetri > 26)
			return (error_in_parsing(&buf));
		else if (newline == 1)
			break ;
	}
	(*tmp_tab)[0][0][0] = nb_tetri;
	ft_strdel(&buf);
	return (close(fd));
}
