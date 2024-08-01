#include "mlx_linux/mlx.h"
#include "../libft/libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//	WINDOW SIZE
# define WIN_LEN	1200
# define WIN_HEIGHT	800

//	EVENT MACROS
# define KEY_PRS_EVT	2
# define KEY_REL_EVT	3
# define BTN_PRS_EVT	4
# define BTN_REL_EVT	5
# define DESTROY_EVT	17

//	MASK MACROS
# define KEY_PRS_MSK		1L<<0
# define KEY_REL_MSK		1L<<1
# define BTN_PRS_MSK		1L<<2
# define BTN_REL_MSK		1L<<3
# define ENTER_WIN_MSK		1L<<4
# define LEAVE_WIN_MSK		1L<<5
# define STRUCT_NOTIFY_MSK	1L<<17

// KEYSYMS
# define ESC_KEY		0xff1b
# define A_KEY			0x0061
# define S_KEY			0x0073
# define D_KEY			0x0064
# define W_KEY			0x0077
# define Q_KEY			0x0071	
# define E_KEY			0x0065
# define UP_KEY			0xff52
# define DOWN_KEY		0xff54
# define LEFT_KEY		0xff51
# define RIGHT_KEY		0xff53
# define SCROLL_UP		4
# define SCROLL_DOWN	5


// Colours
# define WHITE	0xFFF8F8FF
# define RED	0xFFFF0000
# define GREEN	0xFF00FF00
# define BLUE	0xFF0000FF
# define PURPLE	0xFF800080

# define PI	3.14159265358979323846

typedef struct	s_img
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;

typedef struct	s_line
{
	double	dx;
	double	dy;
	int		step;
}				t_line;

typedef struct	s_colour
{
	unsigned char t;
	unsigned char r;
	unsigned char g;
	unsigned char b;
}				t_colour;

typedef struct	s_coord
{
	double		x;
	double		y;
	double		z;
	t_colour	colour;
	
}				t_coord;

typedef struct	s_scale
{	
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
	double	z_min;
	double	z_max;
}				t_scale;

typedef struct	s_grid_data
{
	int		width;
	int		len;
	t_coord centre;
	t_coord	***coords;
	t_scale	range;

}				t_grid_data;

typedef struct	s_mlx_data
{
	void	*ptr;
	void	*win;
	t_img	img;
	char	***file_data;
	t_grid_data	grid;
}				t_mlx_data;

int		key_event(int keysym, t_mlx_data *mlx);

int		mouse_event(int button, int x, int y, t_mlx_data *mlx);

int		close_window(t_mlx_data *mlx);

char	*find_offset(int x, int y, t_img *img);

void	draw_line(t_img *img, t_coord *start, t_coord *end);

void	draw_model(t_mlx_data *mlx);

void	free_file(char ***file_data);

void	free_coords(t_grid_data *grid);

char	***parse_file(char *file_contents, t_mlx_data *mlx);

char	*read_file(int fd, t_mlx_data *mlx);

void	malloc_error(t_mlx_data *mlx);

void 	init_mlx_data(t_mlx_data *mlx);

void	init_img_data(t_img *img, t_mlx_data *mlx);

void	init_grid_data(t_mlx_data *mlx);

void	find_img_centre(t_grid_data *grid);

void	recentre_img(t_grid_data *grid);

double	rad(double degrees);

void	isometric_projection(t_grid_data *grid);

double 	convert_dec(char *nbr);

void	free_mem(t_mlx_data *mlx);

void	clear_img(t_mlx_data *mlx);

void	scale_img(t_grid_data *grid);

bool	within_screen(int x, int y);


void	rot_x_axis(int angle, t_grid_data *grid);

void	rot_y_axis(int angle, t_grid_data *grid);

void	rot_z_axis(int angle, t_grid_data *grid);

void	shift(char var, int step, t_grid_data *grid);

void	zoom(t_grid_data *grid, double factor);


int			rgb_to_hex(t_colour colour);

t_colour	hex_to_rgb(int hex);

t_colour	terp_colour(t_colour color_1, t_colour color_2, float t);

float		find_t(double z, t_grid_data *grid);


