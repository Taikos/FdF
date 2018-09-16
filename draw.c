/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguerin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 20:02:34 by arguerin          #+#    #+#             */
/*   Updated: 2018/03/13 20:23:44 by arguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_px(char *img_data, int x_px, int y_px, int rgb)
{
	int input;

	img_data += 4 * (x_px + 1200 * y_px);
	if (rgb == 1)
	{
		input = (255 << 16) + (0 << 8) + (255);
		img_data[0] = input >> 16 & 0xff;
		img_data[1] = input >> 8 & 0xff;
		img_data[2] = input & 0xff;
	}
	else if (rgb == 2)
	{
		input = (255 << 16) + (255 << 8) + (255);
		img_data[0] = input >> 16 & 0xff;
		img_data[1] = input >> 8 & 0xff;
		img_data[2] = input & 0xff;
	}
	else if (rgb == 3)
	{
		input = (0 << 16) + (255 << 8) + (255);
		img_data[0] = input >> 16 & 0xff;
		img_data[1] = input >> 8 & 0xff;
		img_data[2] = input & 0xff;
	}
}
