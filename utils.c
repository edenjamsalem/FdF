#include "FdF.h"

int	initialize_img(t_mlx_data *mlx)
{
	mlx->img.ptr = mlx_new_image(mlx->ptr, WIN_LEN, WIN_HEIGHT);
	if (!mlx->img.ptr)
	{
		mlx_destroy_window(mlx->ptr, mlx->win);
		mlx_destroy_display(mlx->ptr);
		free(mlx->ptr);
		return (0);
	}
	mlx->img.addr = mlx_get_data_addr(mlx->img.ptr, &mlx->img.bpp, \
							&mlx->img.line_len, &mlx->img.endian);
	if (!mlx->img.addr)
	{
		free(mlx->img.ptr);
		mlx_destroy_window(mlx->ptr, mlx->win);
		mlx_destroy_display(mlx->ptr);
		free(mlx->ptr);
		return (0);
	}
	return (1);
}

char *find_offset(int x, int y, t_img *img)
{
	return (img->addr + ((y * img->line_len) + (x * (img->bpp / 8))));
}

void	my_mlx_pixel_put(t_img *img, t_coord coord, int colour)
{
	char	*dst;

	dst = find_offset(coord.x, coord.y, img);
	*((unsigned int *)dst) = colour;
}