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
# define BTN_REL_MSK 1l<<3
# define ENTER_WIN_MSK 1l<<4
# define LEAVE_WIN_MSK 1l<<5
# define STRUCT_NOTIFY_MSK 1l<<17

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

typedef struct	s_mlx_data
{
	void	*ptr;
	void	*win;
	t_img	img;
}				t_mlx_data;

typedef struct	s_coord
{
	float	x;
	float	y;
}				t_coord;

int		initialize_img(t_mlx_data *mlx);

int		key_event(int keysym, t_mlx_data *mlx);

char	*find_offset(int x, int y, t_img *img);

void	my_mlx_pixel_put(t_img *img, t_coord *coord, int colour);

void	draw_line(t_img *img, t_coord *start, t_coord *end, int colour);
