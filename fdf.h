/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguerin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 20:36:51 by arguerin          #+#    #+#             */
/*   Updated: 2018/03/13 21:22:28 by arguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "get_next_line.h"
# include "mlx.h"

typedef struct	s_fill
{
	double	x_1;
	double	x_2;
	double	y_1;
	double	y_2;
}				t_fill;

typedef struct	s_pximg
{
	void	*img_data;
	int		bpp;
	int		s_l;
	int		endian;
}				t_pximg;

typedef struct	s_matrix
{
	double	column;
	double	line;
	int		*display;
	void	*mlx_ptr;
	void	*win_ptr;
	double	x_init;
	double	y_init;
	double	z_init;
	void	*im;
	double	x_draw;
	double	y_draw;
}				t_matrix;

int				funct_ptr(int keycode, void *key_init);
void			draw_px(char *img_data, int x_px, int y_px, int rgb);
void			screen_draw(t_fill *fill, t_pximg *pximg, int rgb);
t_matrix		*screen_fill_c(int i, t_pximg *pximg, t_matrix *matrix);
t_matrix		*screen_fill_l(int i, t_pximg *pximg, t_matrix *matrix);
t_matrix		*screen_fill(t_pximg *pximg, t_matrix *matrix);
void			bug_display(char *str);
t_matrix		*bug_control(int fd_filecontol, t_matrix *matrix);
void			bug_read(int fd_readcontrol);
void			screen_display(double x, double y, double z, t_matrix *matrix);
t_matrix		*display_init(int fd, t_matrix *matrix);

#endif
