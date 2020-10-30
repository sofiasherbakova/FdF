/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffood <ffood@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 18:56:44 by ffood             #+#    #+#             */
/*   Updated: 2020/01/28 20:36:29 by ffood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		coloring1(int keycode, t_fdf *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (keycode == BOARD_V)
	{
		while (i < data->max_x)
		{
			j = 0;
			while (j < data->max_y)
			{
				if (data->map[j][i].z == 0)
					data->map[j][i].color = YELLOW;
				if (data->map[j][i].z > 0)
					data->map[j][i].color = TEAL;
				if (data->map[j][i].z < 0)
					data->map[j][i].color = RED;
				j++;
			}
			i++;
		}
	}
}

static void		coloring2(int keycode, t_fdf *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (keycode == BOARD_C)
	{
		while (i < data->max_x)
		{
			j = 0;
			while (j < data->max_y)
			{
				if (data->map[j][i].z == 0)
					data->map[j][i].color = PINK;
				if (data->map[j][i].z > 0)
					data->map[j][i].color = VIOLET;
				if (data->map[j][i].z < 0)
					data->map[j][i].color = WHITE;
				j++;
			}
			i++;
		}
	}
}

static void		rotate(int keycode, t_fdf *data)
{
	if (keycode == PAD_1 || keycode == BOARD_1)
		data->rotation->alpha += 0.05;
	else if (keycode == PAD_9 || keycode == BOARD_9)
		data->rotation->alpha -= 0.05;
	else if (keycode == PAD_2 || keycode == BOARD_2)
		data->rotation->beta += 0.05;
	else if (keycode == PAD_8 || keycode == BOARD_8)
		data->rotation->beta -= 0.05;
	else if (keycode == PAD_3 || keycode == BOARD_3)
		data->rotation->gamma += 0.05;
	else if (keycode == PAD_7 || keycode == BOARD_7)
		data->rotation->gamma -= 0.05;
}

int				key_hook(int keycode, t_fdf *data)
{
	if (keycode == BOARD_ESC)
		exit(1);
	if (keycode == ARROW_UP)
		data->shift_y -= 10;
	if (keycode == ARROW_DOWN)
		data->shift_y += 10;
	if (keycode == ARROW_LEFT)
		data->shift_x -= 10;
	if (keycode == ARROW_RIGHT)
		data->shift_x += 10;
	if ((keycode == PAD_PLUS || keycode == BOARD_PLUS) && data->zoom < 200)
		data->zoom += 1;
	if ((keycode == PAD_MINUS || keycode == BOARD_MINUS) && data->zoom > 1)
		data->zoom -= 1;
	if (keycode == BOARD_ENTER)
		data->projection *= -1;
	if (keycode == BOARD_Z)
		data->z_zoom += 1;
	if (keycode == BOARD_X)
		data->z_zoom -= 1;
	coloring1(keycode, data);
	coloring2(keycode, data);
	rotate(keycode, data);
	draw_map(data);
	return (0);
}
