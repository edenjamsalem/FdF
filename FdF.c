#include "mlx_linux/mlx.h"

# define WIN_LEN 1200
# define WIN_HEIGHT 800

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *img, int x, int y, int colour)
{
	char	*dst;

	dst = img->addr + ((y * img->line_len) + (x * (img->bpp / 8)));
	*((unsigned int *)dst) = colour;
}

int	main(void)
{
	void	*mlx;
	void	*window;
	t_data	img;
	int		x;
	int		y;

	mlx = mlx_init();
	window = mlx_new_window(mlx, WIN_LEN, WIN_HEIGHT, "FdF");
	img.img = mlx_new_image(mlx, WIN_LEN, WIN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);

	x = 0;
	y = 10;
	while (x < WIN_LEN)	
		my_mlx_pixel_put(&img, x++, y, 0x000000FF);
	mlx_put_image_to_window(mlx, window, img.img, 0, 0);
	mlx_loop(mlx);
}
