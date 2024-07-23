#include "FdF.h"

void	shift_left(t_mlx_data *mlx)
{
	int	i;
	int j;

	draw_grid(&mlx->img, &mlx->grid, 0x00000000);
	i = 0;
	while (i < mlx->grid.width)
	{
		j = 0;
		while (j < mlx->grid.len)
			mlx->grid.coords[i][j++]->x -= 2;
		i++;
	}
	draw_grid(&mlx->img, &mlx->grid, 0xFFFFFFFF);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.ptr, 0, 0);
}


void	shift_right(t_mlx_data *mlx)
{
	int	i;
	int j;

	draw_grid(&mlx->img, &mlx->grid, 0x00000000);
	i = 0;
	while (i < mlx->grid.width)
	{
		j = 0;
		while (j < mlx->grid.len)
			mlx->grid.coords[i][j++]->x += 2;
		i++;
	}
	draw_grid(&mlx->img, &mlx->grid, 0xFFFFFFFF);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.ptr, 0, 0);
}

void	shift_up(t_mlx_data *mlx)
{
	int	i;
	int j;

	draw_grid(&mlx->img, &mlx->grid, 0x00000000);
	i = 0;
	while (i < mlx->grid.width)
	{
		j = 0;
		while (j < mlx->grid.len)
			mlx->grid.coords[i][j++]->y -= 2;
		i++;
	}
	draw_grid(&mlx->img, &mlx->grid, 0xFFFFFFFF);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.ptr, 0, 0);
}

void	shift_down(t_mlx_data *mlx)
{
	int	i;
	int j;

	draw_grid(&mlx->img, &mlx->grid, 0x00000000);
	i = 0;
	while (i < mlx->grid.width)
	{
		j = 0;
		while (j < mlx->grid.len)
			mlx->grid.coords[i][j++]->y += 2;
		i++;
	}
	draw_grid(&mlx->img, &mlx->grid, 0xFFFFFFFF);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.ptr, 0, 0);
}