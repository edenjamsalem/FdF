#include "mlx_linux/mlx.h"
#include "../libft/libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//	WINDOW SIZE
# define WIN_LEN 1200
# define WIN_HEIGHT 800

//	EVENT MACROS
# define KEY_PRS_EVT 2
# define KEY_REL_EVT 3
# define BTN_PRS_EVT 4
# define BTN_REL_EVT 5
# define DESTROY_EVT 17

//	MASK MACROS
# define KEY_PRS_MSK 1L<<0
# define KEY_REL_MSK 1L<<1
# define BTN_PRS_MSK 1L<<2
# define BTN_REL_MSK 1L<<3
# define ENTER_WIN_MSK 1L<<4
# define LEAVE_WIN_MSK 1L<<5
# define STRUCT_NOTIFY_MSK 1L<<17

// KEYSYMS
# define ESC_KEY 0xff1b

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
	float	x;
	float	y;	
}				t_coord;

typedef struct	s_grid
{
	t_coord	start;
	int		width;
	int		len;
	int		box_width;
	int		box_len;
}				t_grid;

typedef struct	s_mlx_data
{
	void	*ptr;
	void	*win;
	t_img	img;
	char	***file_elements;
	t_grid	grid;
}				t_mlx_data;

int		initialize_img(t_mlx_data *mlx);

int		key_event(int keysym, t_mlx_data *mlx);

char	*find_offset(int x, int y, t_img *img);

void	my_mlx_pixel_put(t_img *img, t_coord *coord, int colour);

void	draw_line(t_img *img, t_coord *start, t_coord *end, int colour);

int		close_window(t_mlx_data *mlx);

void	free_file(char ***file_elements);

void	print_file(char ***file_elements, t_grid *grid);

