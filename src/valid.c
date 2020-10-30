/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffood <ffood@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 18:33:09 by ffood             #+#    #+#             */
/*   Updated: 2020/01/28 20:39:45 by ffood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		check_el(char *el)
{
	int			i;

	i = 0;
	if (el[i] == '-')
		i++;
	while (el[i] >= '0' && el[i] <= '9')
		i++;
	if (el[i] == ',')
	{
		if (el[i + 1] != '0' && el[i + 2] != 'x')
			error_out();
		i += 3;
		while ((el[i] >= '0' && el[i] <= '9')
	|| (el[i] >= 'a' && el[i] <= 'f') || (el[i] >= 'A' && el[i] <= 'F'))
			i++;
	}
	if (el[i] != '\0')
		error_out();
}

static int		count_size(char *line)
{
	int			size;
	char		**tmp;

	tmp = ft_strsplit((const char*)line, ' ');
	size = 0;
	while (tmp[size])
	{
		check_el(tmp[size]);
		free(tmp[size]);
		size++;
	}
	free(tmp);
	return (size);
}

static void		check_file(char *file_name)
{
	while (*file_name)
		file_name++;
	file_name = file_name - 4;
	if (ft_strcmp(file_name, ".fdf") != 0)
		error_out();
}

void			check_valid(char *file_name, t_fdf *data)
{
	char		*line;
	int			next_size;
	int			fd;

	data->max_y = 0;
	check_file(file_name);
	if ((fd = open(file_name, O_RDONLY)) < 0)
		error_out();
	if (!(get_next_line(fd, &line)))
		error_out();
	data->max_y++;
	data->max_x = count_size(line);
	free(line);
	while (get_next_line(fd, &line) > 0)
	{
		next_size = count_size(line);
		free(line);
		if (next_size != data->max_x)
			error_out();
		data->max_y++;
	}
	close(fd);
}
