/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reya <reya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:23:17 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/12/02 23:29:46 by reya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/stat.h>

char		get_file_type(const char *path)
{
	struct stat		buff;
	char			c;

	if (stat(path, &buff) == -1)
		return ('\0');
	c = '0';
	if (S_ISDIR(buff.st_mode))
		c = 'd';
	else if (S_ISFIFO(buff.st_mode))
		c = 'p';
	else if (S_ISCHR(buff.st_mode))
		c = 'c';
	else if (S_IFLNK & buff.st_mode)
	{
		if (S_ISREG(buff.st_mode))
			c = '-';
		else if (S_ISBLK(buff.st_mode))
			c = 'b';
		else if (S_ISSOCK(buff.st_mode))
			c = 's';
		else
			c = 'l';
	}
	return (c);
}
