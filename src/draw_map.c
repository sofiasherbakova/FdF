/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffood <ffood@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:33:42 by bhugo             #+#    #+#             */
/*   Updated: 2020/01/29 17:19:59 by ffood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Drawing a menu and a map by using Bresenham's line algorithm
*/

void	draw_map(t_fdf *data)
{
	t_dot	a;

	a.y = 0;
	ft_bzero(data->image_pix, SIZE_WIN * SIZE_WIN * (data->bpp / 8));
	while (a.y < data->max_y)
	{
		a.x = 0;
		while (a.x < data->max_x)
		{
			if (a.x < data->max_x - 1)
				draw_line(a, a.x + 1, a.y, data);
			if (a.y < data->max_y - 1)
				draw_line(a, a.x, a.y + 1, data);
			a.x++;
		}
		a.y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	if (SIZE_WIN == 1000)
		menu(data);
}
