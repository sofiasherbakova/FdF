/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffood <ffood@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 13:55:50 by ffood             #+#    #+#             */
/*   Updated: 2020/01/29 17:29:33 by ffood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include "../libft/libft.h"
# define SIZE_WIN			1000
# define SIZE_MENU			210
# define ZOOM				10
# define Z_ZOOM				1
# define PROJECTION			-1
# define TEXT				"- - - - MENU - - - -"
# define TEXT1				"arrows : shift"
# define TEXT2				"+ / -  : zoom"
# define TEXT3				"enter  : projection"
# define TEXT4				"Z / X  : height"
# define TEXT5				"<esc>  : quit"
# define TEXT6				"1 / 9  : rotation X"
# define TEXT7				"2 / 8  : rotation Y"
# define TEXT8				"3 / 7  : rotation Z"
# define TEXT9				"C / V  : color"
# define ARROW_UP			126
# define ARROW_DOWN			125
# define ARROW_LEFT			123
# define ARROW_RIGHT		124
# define PAD_0			    82
# define PAD_1			    83
# define PAD_2			    84
# define PAD_3			    85
# define PAD_4			    86
# define PAD_5			    87
# define PAD_6			    88
# define PAD_7			    89
# define PAD_8			    91
# define PAD_9			    92
# define PAD_PLUS		    69
# define PAD_MINUS		    78
# define BOARD_ESC		    53
# define BOARD_ENTER		36
# define BOARD_Z			6
# define BOARD_X			7
# define BOARD_0			29
# define BOARD_1			18
# define BOARD_2			19
# define BOARD_3			20
# define BOARD_4			21
# define BOARD_5			23
# define BOARD_6			22
# define BOARD_7			26
# define BOARD_8			28
# define BOARD_9			25
# define BOARD_PLUS		    24
# define BOARD_MINUS		27
# define BOARD_C			8
# define BOARD_V			9
# define WHITE              0xf7e8e8
# define YELLOW             0xffe837
# define TEAL               0x05a19c
# define RED                0xd25959
# define PINK               0xe42c64
# define VIOLET             0x614ad3
# define BLUE 				0x0000ff

typedef struct	s_dot
{
	int		x;
	int		y;
	int		z;
}				t_dot;

typedef struct	s_info
{
	int		dx;
	int		dy;
	int		lx;
	int		ly;
	int		length;
	int		color;
}				t_info;

typedef struct	s_map
{
	int			z;
	int			color;
}				t_map;

typedef struct	s_rotation
{
	double		alpha;
	double		beta;
	double		gamma;
}				t_rotation;

typedef struct	s_fdf
{
	void		*mlx_ptr;
	void		*img_ptr;
	void		*win_ptr;
	int			*image_pix;
	int			zoom;
	int			shift_x;
	int			shift_y;
	t_map		**map;
	t_rotation	*rotation;
	int			max_x;
	int			max_y;
	int			bpp;
	int			projection;
	int			z_zoom;
}				t_fdf;

void			check_valid(char *file_name, t_fdf *data);
void			error_out(void);
void			draw_line(t_dot a, int x2, int y2, t_fdf *data);
void			ft_read_file(char *file, t_fdf *data);
void			draw_map(t_fdf *data);
void			iso(int *x, int *y, int z);
void			zoom(int *x, int *y, t_fdf *data);
void			shift(int *x, int *y, t_fdf *data);
int				key_hook(int keycode, t_fdf *data);
void			menu(t_fdf *data);
void			rotate_x(int *y, int *z, double alpha);
void			rotate_y(int *x, int *z, double beta);
void			rotate_z(int *x, int *y, double gamma);
void			isometric(int *x, int *y, int z);
int				max(int a, int b);

#endif
