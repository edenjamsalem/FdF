#include "FdF.h"

void	rotate_clockwise(t_mlx_data *mlx, t_grid_data *grid)
{
	int	i;
	int	j;
	float x;
	float y;
	float new_x;
	float new_y;

	draw_grid(&mlx->img, grid, 0x00000000);
	find_centre(&mlx->grid);
	i = 0;
	while (i < grid->width)
	{
		j = 0;
		while (j < grid->len)
		{
			x = grid->coords[i][j]->x - grid->centre->x;
			y = grid->coords[i][j]->y - grid->centre->y;
			new_x = (x * cos(rad(1))) - (y * sin(rad(1)));
			new_y = (x * sin(rad(1))) + (y * cos(rad(1)));
			grid->coords[i][j]->x =  new_x + grid->centre->x;
			grid->coords[i][j]->y =  new_y + grid->centre->y;
			j++;
		}
		i++;
	}
	draw_grid(&mlx->img, grid, 0xFFFFFFFF);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.ptr, 0, 0);
}

void	rotate_anticlockwise(t_mlx_data *mlx, t_grid_data *grid)
{
	int	i;
	int	j;
	float x;
	float y;
	float new_x;
	float new_y;

	draw_grid(&mlx->img, grid, 0x00000000);
	find_centre(&mlx->grid);
	i = 0;
	while (i < grid->width)
	{
		j = 0;
		while (j < grid->len)
		{
			x = grid->coords[i][j]->x - grid->centre->x;
			y = grid->coords[i][j]->y - grid->centre->y;
			new_x = (x * cos(rad(1))) + (y * sin(rad(1)));
			new_y = -(x * sin(rad(1))) + (y * cos(rad(1)));
			grid->coords[i][j]->x =  new_x + grid->centre->x;
			grid->coords[i][j]->y =  new_y + grid->centre->y;
			j++;
		}
		i++;
	}
	draw_grid(&mlx->img, grid, 0xFFFFFFFF);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.ptr, 0, 0);
}
