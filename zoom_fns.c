#include "FdF.h"

void	zoom_in(t_mlx_data *mlx)
{
	draw_grid(&mlx->img, &mlx->grid, 0x00000000);
	mlx->grid.box_len++;
	mlx->grid.box_width++;
	reset_centre(&mlx->grid);
	set_start_from_centre(&mlx->grid);
	reset_grid_coords(&mlx->grid);
	draw_grid(&mlx->img, &mlx->grid, 0xFFFFFFFF);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.ptr, 0, 0);
}

void	zoom_out(t_mlx_data *mlx)
{
	draw_grid(&mlx->img, &mlx->grid, 0x00000000);
	if (mlx->grid.box_len > 0)
		mlx->grid.box_len--;
	if (mlx->grid.box_width > 0)
		mlx->grid.box_width--;
	reset_centre(&mlx->grid);
	set_start_from_centre(&mlx->grid);
	reset_grid_coords(&mlx->grid);
	draw_grid(&mlx->img, &mlx->grid, 0xFFFFFFFF);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.ptr, 0, 0);
}
