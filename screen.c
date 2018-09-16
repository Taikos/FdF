/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguerin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 20:03:33 by arguerin          #+#    #+#             */
/*   Updated: 2018/03/13 20:48:38 by arguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		screen_draw(t_fill *fill, t_pximg *pximg, int rgb)
{
	int		i;
	double	length_pyth;
	double	x_px;
	double	y_px;

	i = 0;
	length_pyth = sqrt(pow((fill->x_2 - fill->x_1), 2)
			+ pow((fill->y_2 - fill->y_1), 2));
	while (i < length_pyth)
	{
		x_px = (i / length_pyth) * (fill->x_2 - fill->x_1) + fill->x_1;
		y_px = (i / length_pyth) * (fill->y_2 - fill->y_1) + fill->y_1;
		if (x_px >= 0 && y_px >= 0 && x_px < 1200 && y_px < 1200)
			draw_px(pximg->img_data, x_px, y_px, rgb);
		i++;
	}
}

t_matrix	*screen_fill_c(int i, t_pximg *pximg, t_matrix *matrix)
{
	t_fill	*fill_2;

	if (!(fill_2 = malloc(sizeof(t_fill) + 1)))
		bug_display("Impossible action-struct with not enough memory alloc\n");
	fill_2->x_1 = matrix->x_draw;
	fill_2->y_1 = matrix->y_draw - matrix->display[i] * matrix->z_init;
	fill_2->x_2 = matrix->x_draw - 30;
	fill_2->y_2 = matrix->y_draw + 30
		- matrix->display[i + (int)matrix->column] * matrix->z_init;
	if (matrix->display[i] * matrix->z_init > 0
			|| matrix->display[i + (int)matrix->column] * matrix->z_init > 0)
		screen_draw(fill_2, pximg, 1);
	else if (matrix->display[i] * matrix->z_init == 0
			|| matrix->display[i + (int)matrix->column] * matrix->z_init == 0)
		screen_draw(fill_2, pximg, 2);
	else
		screen_draw(fill_2, pximg, 3);
	free(fill_2);
	return (matrix);
}

t_matrix	*screen_fill_l(int i, t_pximg *pximg, t_matrix *matrix)
{
	t_fill	*fill_1;

	if (!(fill_1 = malloc(sizeof(t_fill) + 1)))
		bug_display("Impossible action-struct with not enough memory alloc\n");
	fill_1->x_1 = matrix->x_draw;
	fill_1->y_1 = matrix->y_draw - ((matrix->display[i]) * matrix->z_init);
	fill_1->x_2 = matrix->x_draw + 30;
	fill_1->y_2 = matrix->y_draw + 30 - matrix->display[i + 1] * matrix->z_init;
	if (matrix->display[i] * matrix->z_init > 0
			|| matrix->display[i + 1] * matrix->z_init > 0)
		screen_draw(fill_1, pximg, 1);
	else if (matrix->display[i] * matrix->z_init == 0
			|| matrix->display[i + 1] * matrix->z_init == 0)
		screen_draw(fill_1, pximg, 2);
	else
		screen_draw(fill_1, pximg, 3);
	free(fill_1);
	return (matrix);
}

t_matrix	*screen_fill(t_pximg *pximg, t_matrix *matrix)
{
	int i;

	i = 0;
	matrix->x_draw = matrix->x_init + 30 * matrix->line - 30;
	matrix->y_draw = matrix->y_init + 30;
	while (i < matrix->column * matrix->line)
	{
		if ((i + 1) % (int)matrix->column)
			screen_fill_l(i, pximg, matrix);
		if (i / matrix->column + 1 < matrix->line)
			screen_fill_c(i, pximg, matrix);
		matrix->x_draw += 30;
		matrix->y_draw += 30;
		if ((i + 1) % (int)matrix->column == 0)
		{
			matrix->x_draw = matrix->x_init + 30 * matrix->line
				- (30 * (i / matrix->column + 1));
			matrix->y_draw = matrix->y_init + (30 * (i / matrix->column + 1));
		}
		i++;
	}
	return (matrix);
}

void		screen_display(double x, double y, double z, t_matrix *matrix)
{
	t_pximg *pximg;

	matrix->x_init = x;
	matrix->y_init = y;
	matrix->z_init = z;
	matrix->im = mlx_new_image(matrix->mlx_ptr, 1200, 1200);
	if (!(pximg = malloc(sizeof(t_pximg) + 1)))
		bug_display("Impossible action-struct with not enough memory alloc\n");
	pximg->bpp = 4 * 8;
	pximg->s_l = 4 * 1200;
	pximg->endian = 0;
	pximg->img_data = mlx_get_data_addr(matrix->im, &pximg->bpp,
			&pximg->s_l, &pximg->endian);
	screen_fill(pximg, matrix);
	mlx_put_image_to_window(matrix->mlx_ptr, matrix->win_ptr, matrix->im, 0, 0);
	mlx_key_hook(matrix->win_ptr, funct_ptr, matrix);
	mlx_loop(matrix->mlx_ptr);
	free(matrix);
	free(pximg);
}
