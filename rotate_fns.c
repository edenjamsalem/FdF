#include "FdF.h"

void	rotate_forward(t_mlx_data *mlx, t_grid_data *grid)
{
	int		i;
	int		j;
	float	x;
	float	y;

	grid->angles.y_axis += PI / 180;
	draw_grid(&mlx->img, &mlx->grid, 0x00000000);
	i = 0;
	while (i < grid->width)
	{
		j = 0;
		while (j < grid->len)
		{
			x = grid->centre.x - grid->coords[i][j]->x ;
			y = grid->centre.y - grid->coords[i][j]->y ;
			grid->coords[i][j]->x += x * sin(grid->angles.y_axis);
			grid->coords[i][j]->y += y * sin(grid->angles.y_axis);
			j++;
		}
		i++;
	}
	draw_grid(&mlx->img, &mlx->grid, 0xFFFFFFFF);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.ptr, 0, 0);
}