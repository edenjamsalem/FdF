/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:41:10 by eamsalem          #+#    #+#             */
/*   Updated: 2024/11/01 07:46:26 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_mac/mlx.h"
#include "libft/libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//	WINDOW SIZE
#define WIN_LEN	1200
#define WIN_HEIGHT	800

//	EVENT MACROS
#define KEY_PRS_EVT	2
#define KEY_REL_EVT	3
#define BTN_PRS_EVT	4
#define BTN_REL_EVT	5
#define DESTROY_EVT	17

// KEYSYMS
#define ESC_KEY			0x35
#define A_KEY			0x00
#define S_KEY           0x01
#define D_KEY           0x02
#define W_KEY			0x0D
#define Q_KEY			0x0C
#define E_KEY			0x0E
#define UP_KEY			0x7E
#define DOWN_KEY		0x7D
#define LEFT_KEY		0x7B
#define RIGHT_KEY		0x7C
#define SCROLL_UP		4
#define SCROLL_DOWN		5

// COLOURS
#define WHITE	0xFFF8F8FF
#define RED	0xFFFF0000
#define GREEN	0xFF00FF00
#define BLUE	0xFF0000FF
#define PURPLE	0xFF800080

#define PI	3.14159265358979323846

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;

typedef struct s_line
{
	double	dx;
	double	dy;
	int		step;
}				t_line;

typedef struct s_colour
{
	unsigned char	t;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}				t_colour;

typedef struct s_coord
{
	double		x;
	double		y;
	double		z;
	t_colour	colour;

}				t_coord;

typedef struct s_scale
{
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
	double	z_min;
	double	z_max;
}				t_scale;

typedef struct s_grid_data
{
	int		width;
	int		len;
	t_coord	centre;
	t_coord	***coords;
	t_scale	range;

}				t_grid_data;

typedef struct s_mlx_data
{
	void		*ptr;
	void		*win;
	t_img		img;
	char		***file_data;
	t_grid_data	grid;
}				t_mlx_data;

typedef enum {
    X_AXIS,
    Y_AXIS,
    Z_AXIS
} t_axis;

int			key_event(int keysym, t_mlx_data *mlx);

int			mouse_event(int button, int x, int y, t_mlx_data *mlx);

int			close_window(t_mlx_data *mlx);

char		*find_offset(int x, int y, t_img *img);

void		draw_line(t_img *img, t_coord *start, t_coord *end);

void		draw_model(t_mlx_data *mlx);

void		free_file(char ***file_data);

void		free_coords(t_grid_data *grid);

char		***parse_file(char *file_contents, t_mlx_data *mlx);

char		*read_file(int fd, t_mlx_data *mlx);

void		malloc_error(t_mlx_data *mlx);

void		init_mlx_data(t_mlx_data *mlx);

void		init_img_data(t_img *img, t_mlx_data *mlx);

void		init_grid_data(t_mlx_data *mlx);

void		init_grid_coords(t_grid_data *grid, t_mlx_data *mlx);

void		init_grid_scale(t_grid_data *grid);

void		init_grid_colours(t_grid_data *grid);

void		find_img_centre(t_grid_data *grid);

void		recentre_img(t_grid_data *grid);

double		rad(double degrees);

void		isometric_projection(t_grid_data *grid);

double		convert_dec(char *nbr);

void		free_mem(t_mlx_data *mlx);

void		clear_img(t_mlx_data *mlx);

void		scale_img(t_grid_data *grid);

bool		within_screen(int x, int y);

void		rotate(t_axis axis, int angle, t_grid_data *grid);

void		rot_x_axis(int angle, t_coord *coord, t_coord *centre);

void		rot_y_axis(int angle, t_coord *coord, t_coord *centre);

void		rot_z_axis(int angle, t_coord *coord, t_coord *centre);

void		shift_x(int step, t_grid_data *grid);

void		shift_y(int step, t_grid_data *grid);

void		zoom(t_grid_data *grid, double factor);

int			rgb_to_hex(t_colour colour);

t_colour	hex_to_rgb(int hex);

t_colour	terp_colour(t_colour color_1, t_colour color_2, float t);

double		find_t(double z, t_grid_data *grid);
