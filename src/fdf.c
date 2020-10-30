/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffood <ffood@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 14:55:26 by ffood             #+#    #+#             */
/*   Updated: 2020/01/29 17:15:15 by ffood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error_out(void)
{
	ft_putendl("Error!");
	exit(1);
}

/*
** mlx_pixel_put рисует окно меню
** mlx_string_put отображение текста
*/

void	menu(t_fdf *data)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < SIZE_WIN)
	{
		x = 0;
		while (x < SIZE_MENU)
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, x++, y, BLUE);
		y++;
	}
	mlx_string_put(data->mlx_ptr, data->win_ptr, 5, 300, 0xFFFFFF, TEXT);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 330, 0xFFFFFF, TEXT1);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 360, 0xFFFFFF, TEXT2);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 390, 0xFFFFFF, TEXT3);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 420, 0xFFFFFF, TEXT4);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 450, 0xFFFFFF, TEXT5);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 480, 0xFFFFFF, TEXT6);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 510, 0xFFFFFF, TEXT7);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 540, 0xFFFFFF, TEXT8);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 570, 0xFFFFFF, TEXT9);
}

/*
** data_init заполнение структуры входными данными:
** check_valid считывание длины и ширины
** ft_read_file - считывание цвета и карты
** shift_x, shift_y расчет первоначального сдвига для первого изображения карты
** projection - параллельная проекция
** rotation - угол наклона по каждой оси
*/

void	data_init(t_fdf *data, char **argv)
{
	check_valid(argv[1], data);
	ft_read_file(argv[1], data);
	data->zoom = ZOOM;
	data->z_zoom = Z_ZOOM;
	if (!(data->rotation = (t_rotation *)malloc(sizeof(*data->rotation))))
		error_out();
	data->rotation->alpha = (double)0;
	data->rotation->beta = (double)0;
	data->rotation->gamma = (double)0;
	data->shift_x = (SIZE_WIN + SIZE_MENU - data->max_x * data->zoom) / 2;
	data->shift_y = (SIZE_WIN - data->max_y * data->zoom) / 2;
	data->projection = PROJECTION;
}

/*
** data_init  заполнение струкутуры входными данными
** mlx_init() создает соединение с графической системой
** mlx_new_window() открывает окно
** mlx_get_data_addr() считывание данных о системе
** mlx_hook() считывание событий с клавиутуры и мыши
** mlx_loop() не дает закрыться окну
*/

int		main(int argc, char **argv)
{
	int		size_line;
	int		end;
	int		i;
	int		j;
	t_fdf	*data;

	i = 0;
	j = 0;
	if (argc != 2)
		error_out();
	if (!(data = (t_fdf *)malloc(sizeof(*data))))
		error_out();
	data_init(data, argv);
	if ((data->mlx_ptr = mlx_init()) == NULL)
		error_out();
	data->win_ptr = mlx_new_window(data->mlx_ptr, SIZE_WIN, SIZE_WIN, "FDF");
	data->img_ptr = mlx_new_image(data->mlx_ptr, SIZE_WIN, SIZE_WIN);
	data->image_pix = (int *)
		mlx_get_data_addr(data->img_ptr, &data->bpp, &size_line, &end);
	draw_map(data);
	mlx_hook(data->win_ptr, 2, 0, key_hook, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
