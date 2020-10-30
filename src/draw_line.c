/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffood <ffood@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 18:32:19 by ffood             #+#    #+#             */
/*   Updated: 2020/01/29 17:29:50 by ffood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_pixel(int x, int y, t_fdf *data, int color)
{
	int		i;

	if (y >= 0 && y < SIZE_WIN && x >= 0 && x < SIZE_WIN)
	{
		i = SIZE_WIN * y + x;
		data->image_pix[i] = color;
	}
}

void	ft_ly(t_dot a, t_fdf *data, t_info param)
{
	int		d;

	d = -1 * param.lx;
	param.length++;
	while (param.length--)
	{
		set_pixel(a.x, a.y, data, param.color);
		a.x += param.dx;
		d += 2 * param.ly;
		if (d > 0)
		{
			d -= 2 * param.lx;
			a.y += param.dy;
		}
	}
}

void	ft_lx(t_dot a, t_fdf *data, t_info param)
{
	int d;

	d = -1 * param.ly;
	param.length++;
	while (param.length--)
	{
		set_pixel(a.x, a.y, data, param.color);
		a.y += param.dy;
		d += 2 * param.lx;
		if (d > 0)
		{
			d -= 2 * param.ly;
			a.x += param.dx;
		}
	}
}

void	dot_position(t_dot *a, t_fdf *data)
{
	a->z = data->map[a->y][a->x].z * data->z_zoom;
	a->x *= data->zoom;
	a->y *= data->zoom;
	rotate_x(&a->y, &a->z, data->rotation->alpha);
	rotate_y(&a->x, &a->z, data->rotation->beta);
	rotate_z(&a->x, &a->y, data->rotation->gamma);
	if (data->projection == 1)
		isometric(&a->x, &a->y, a->z);
	a->x += data->shift_x;
	a->y += data->shift_y;
}

void	draw_line(t_dot a, int x, int y, t_fdf *data)
{
	t_dot	b;
	t_info	param;

	b.x = x;
	b.y = y;
	param.color = data->map[a.y][a.x].color;
	dot_position(&a, data);
	dot_position(&b, data);
	param.dx = (b.x - a.x >= 0 ? 1 : -1);
	param.dy = (b.y - a.y >= 0 ? 1 : -1);
	param.lx = abs(b.x - a.x);
	param.ly = abs(b.y - a.y);
	param.length = max(param.lx, param.ly);
	if (param.length == 0)
		set_pixel(a.x, a.y, data, param.color);
	if (param.ly <= param.lx)
		ft_ly(a, data, param);
	else
		ft_lx(a, data, param);
}
