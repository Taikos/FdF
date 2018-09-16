/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguerin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 20:07:46 by arguerin          #+#    #+#             */
/*   Updated: 2018/03/13 20:39:09 by arguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		funct_ptr(int keycode, void *key_init)
{
	t_matrix *keyboard;

	keyboard = (t_matrix*)key_init;
	if (keycode == 53)
	{
		mlx_destroy_window(keyboard->mlx_ptr, keyboard->win_ptr);
		exit(0);
	}
	return (0);
}
