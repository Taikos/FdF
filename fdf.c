/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguerin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 20:05:16 by arguerin          #+#    #+#             */
/*   Updated: 2018/03/13 21:04:28 by arguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matrix	*display_init(int fd, t_matrix *matrix)
{
	char	*rd;
	char	**tab;
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	if (!(matrix->display = malloc(sizeof(int)
			* ((matrix->column * matrix->line) + 1))))
		bug_display("Impossible action - Malloc initialisation issue\n");
	while (get_next_line(fd, &rd))
	{
		tab = ft_strsplit(rd, ' ');
		while (tab[i])
		{
			matrix->display[nb] = ft_atoi(tab[i]);
			i++;
			nb++;
		}
		i = 0;
		free(tab);
	}
	return (matrix);
}

int			main(int n, char **file)
{
	int			fd_readcontrol;
	int			fd_filecontrol;
	int			fd;
	t_matrix	*matrix;

	if (!(matrix = malloc(sizeof(t_matrix) + 1)))
		bug_display("Impossible action-struct with not enough memory alloc\n");
	if (n == 2)
	{
		fd_readcontrol = open(file[1], O_RDONLY);
		bug_read(fd_readcontrol);
		close(fd_readcontrol);
		fd_filecontrol = open(file[1], O_RDONLY);
		bug_control(fd_filecontrol, matrix);
		close(fd_filecontrol);
		fd = open(file[1], O_RDONLY);
		display_init(fd, matrix);
		matrix->mlx_ptr = mlx_init();
		matrix->win_ptr = mlx_new_window(matrix->mlx_ptr, 1200, 1200, "FdF");
		screen_display(200, 20, 4, matrix);
		close(fd);
	}
	else
		bug_display("Impossible action - add unique fdf file and try again\n");
	return (0);
}
