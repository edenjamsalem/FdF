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
# define ESC_KEY	0xff1b
# define A_KEY		0x0061
# define S_KEY		0x0073
# define D_KEY		0x0064
# define X_KEY		0x0078
# define Z_KEY		0x007a
# define W_KEY		0x0077
# define UP_KEY		0xff52
# define DOWN_KEY	0xff54
# define LEFT_KEY	0xff51
# define RIGHT_KEY	0xff53

# define PI	3.14159265358979323846

typedef struct	s_img
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;

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
	t_coord *centre;
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

char	*find_offset(int x, int y, t_img *img);

void	my_mlx_pixel_put(t_img *img, t_coord *coord, int colour);

void	draw_line(t_img *img, t_coord *start, t_coord *end, int colour);

void	draw_grid_points(t_img *img, t_grid_data *grid, int colour);

void	draw_grid(t_img *img, t_grid_data *grid, int colour);

int		close_window(t_mlx_data *mlx);

void	free_file(char ***file_elements);

void	free_coords(t_grid_data *grid);

void	print_file(char ***file_elements, t_grid_data *grid);

char	***parse_file(int fd);

int 	init_mlx_win(t_mlx_data *mlx);

int		init_img(t_img *img, t_mlx_data *mlx);

int		init_grid_coords(t_grid_data *grid, char ***file_elements);

int		init_grid_data(t_grid_data *grid, char ***file_elements);

void	recentre(t_grid_data *grid);

double	rad(int	degrees);

void	shift_left(t_mlx_data *mlx);

void	shift_right(t_mlx_data *mlx);

void	shift_up(t_mlx_data *mlx);

void	shift_down(t_mlx_data *mlx);

void	zoom_in(t_mlx_data *mlx, t_grid_data *grid);

void	zoom_out(t_mlx_data *mlx, t_grid_data *grid);

void	rotate_clockwise(t_mlx_data *mlx, t_grid_data *grid);

void	rotate_anticlockwise(t_mlx_data *mlx, t_grid_data *grid);
