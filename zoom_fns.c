#include "FdF.h"

void	zoom_out(t_mlx_data *mlx, t_grid_data *grid)
{
	int		i;
	int		j;
	float	x;
	float	y;

	draw_grid(&mlx->img, &mlx->grid, 0x00000000);
	i = 0;
	while (i < grid->width)
	{
		j = 0;
		while (j < grid->len)
		{
			x =  grid->coords[i][j]->x - grid->centre.x;
			y =  grid->coords[i][j]->y - grid->centre.y;
			grid->coords[i][j]->x += x;
			grid->coords[i][j]->y += y;
			j++;
		}
		i++;
	}
	draw_grid(&mlx->img, &mlx->grid, 0xFFFFFFFF);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.ptr, 0, 0);
}