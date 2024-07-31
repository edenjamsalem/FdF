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
# define X_KEY			0x0078
# define Z_KEY			0x007a
# define UP_KEY			0xff52
# define DOWN_KEY		0xff54
# define LEFT_KEY		0xff51
# define RIGHT_KEY		0xff53
# define SCROLL_UP		4
# define SCROLL_DOWN	5

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


typedef struct	s_coord
{
	double	x;
	double	y;
	double	z;
}				t_coord;

typedef struct	s_grid_data
{
	int		width;
	int		len;
	t_coord centre;
	t_coord	***coords;
}				t_grid_data;

typedef struct	s_mlx_data
{
	void	*ptr;
	void	*win;
	t_img	img;
	char	***file_elements;
	t_grid_data	grid;
}				t_mlx_data;

int		key_event(int keysym, t_mlx_data *mlx);

int		mouse_event(int button, int x, int y, t_mlx_data *mlx);

int		close_window(t_mlx_data *mlx);

void	put_pixel(t_img *img, t_coord *coord, int colour);

void	draw_line(t_img *img, t_coord *start, t_coord *end, int colour);

void	draw_grid_points(t_img *img, t_grid_data *grid, int colour);

void	draw_model(t_img *img, t_grid_data *grid, int colour);

void	free_file(char ***file_elements);

void	free_coords(t_grid_data *grid);

char	***parse_file(char *file_contents);

char	*read_file(int fd);

void	clear_image(t_mlx_data *mlx);

void	malloc_error();

void 	init_mlx_win(t_mlx_data *mlx);

void	init_img(t_img *img, t_mlx_data *mlx);

void	init_grid_data(t_grid_data *grid, char ***file_elements);

void	find_centre(t_grid_data *grid);

void	recentre(t_grid_data *grid);

double	rad(double degrees);

void	isometric_projection(t_grid_data *grid);

double 	convert_dec(char *nbr);

char	*find_offset(int x, int y, t_img *img);


void	shift_x(t_grid_data *grid, int step);

void	shift_y(t_grid_data *grid, int step);

void	zoom(t_grid_data *grid, double factor);


void	rot_x_axis(t_grid_data *grid, int angle);

void	rot_y_axis(t_grid_data *grid, int angle);

void	rot_z_axis(t_grid_data *grid, int angle);
