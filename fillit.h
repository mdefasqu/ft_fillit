/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 12:25:45 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/12/10 18:57:17 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>

typedef struct		s_tetri
{
	int				**pos;
	char			signature;
	struct s_tetri	*next;
}					t_tetri;

/*
** Parser_read.c
*/
int					read_file(char **argv, int ****tmp_tab);

/*
** Parser_algo.c
*/
int					is_valid_tetriminos(char *buf);

/*
** create_list.c
*/
int					**create_form(const char *buf);

/*
** Permutation.c
*/
void				permutation(int *order, int k, int ****list, char **tab);

/*
** place_in_grid.c
*/
int					place(int **list, char **tab, int index);
int					fill_tab(int ***list, int *order, char **tab);

/*
** Free.c
*/

void				free_final_tab(int ****tab, int len);

/*
**	Main.c
*/
void				print_list_debug(t_tetri *list);

/*
** resolve.c
*/
void				resolve(int ***final_tab);

#endif
