/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bug.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguerin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 20:01:48 by arguerin          #+#    #+#             */
/*   Updated: 2018/03/13 21:03:48 by arguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		bug_display(char *str)
{
	ft_putstr(str);
	exit(0);
}

t_matrix	*bug_control(int fd_filecontrol, t_matrix *matrix)
{
	char	*rd;
	char	**tab;
	int		i;
	int		ref_c;
	int		ref_l;

	i = 0;
	ref_c = 0;
	ref_l = 0;
	while (get_next_line(fd_filecontrol, &rd))
	{
		tab = ft_strsplit(rd, ' ');
		while (tab[i])
			i++;
		ref_l++;
		if (ref_l == 1)
			ref_c = i;
		if (ref_c != i)
			bug_display("Impossible action -file- change it and try again\n");
		i = 0;
	}
	matrix->column = ref_c;
	matrix->line = ref_l;
	return (matrix);
}

void		bug_read(int fd_readcontrol)
{
	char	*buf;

	while (read(fd_readcontrol, &buf, 1))
	{
		if (read(fd_readcontrol, &buf, 1) == -1)
			bug_display("Impossible action -read- change it and try again\n");
	}
}
