/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffood <ffood@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:41:57 by ffood             #+#    #+#             */
/*   Updated: 2020/01/29 13:17:58 by ffood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_map	*map_int(char *line, t_map *map)
{
	int		i;
	char	**tmp;
	char	**tmp_free;
	char	*if_color;

	i = 0;
	if (!(tmp = ft_strsplit(line, ' ')))
		error_out();
	tmp_free = tmp;
	while (tmp[i])
	{
		map->z = ft_atoi(tmp[i]);
		if (map->z > 2147483645 || map->z < -2147483645)
			error_out();
		if ((if_color = ft_strchr(tmp[i], ',')))
			map->color = ft_atoi_base(if_color + 3, 16);
		else
			map->color = 0xFFFFFF;
		free(tmp[i]);
		map++;
		tmp++;
	}
	free(tmp_free);
	return (map);
}

void			ft_read_file(char *file, t_fdf *data)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (!(data->map = (t_map **)malloc(sizeof(t_map *) * data->max_y)))
		error_out();
	while (i < data->max_y)
	{
		if (!(data->map[i++] = (t_map *)malloc(sizeof(t_map) * data->max_x)))
			error_out();
	}
	i = 0;
	while (i < data->max_y)
	{
		if (get_next_line(fd, &line) == -1)
			error_out();
		map_int(line, data->map[i++]);
		free(line);
	}
	close(fd);
}
