#include "FdF.h"

int	key_event(int keysym, t_mlx_data *mlx)
{
	draw_grid(&mlx->img, &mlx->grid, 0x00000000);
//	draw_grid_points(&mlx->img, grid, 0x00000000);
	if (keysym == ESC_KEY)
		close_window(mlx);

	if (keysym == A_KEY)
		rev_rot_z_axis(&mlx->grid);	
	if (keysym == D_KEY)
		rot_z_axis(&mlx->grid);
	if (keysym == W_KEY)
		rot_x_axis(&mlx->grid);
	if (keysym == S_KEY)
		rev_rot_x_axis(&mlx->grid);
	if (keysym == Q_KEY)
		rot_y_axis(&mlx->grid);
	if (keysym == E_KEY)
		rev_rot_y_axis(&mlx->grid);


	if (keysym == Z_KEY)
		zoom_in(&mlx->grid);
	if (keysym == X_KEY)
		zoom_out(&mlx->grid);

	if (keysym == RIGHT_KEY)
		shift_right(&mlx->grid);
	if (keysym == LEFT_KEY)
		shift_left(&mlx->grid);
	if (keysym == UP_KEY)
		shift_up(&mlx->grid);
	if (keysym == DOWN_KEY)
		shift_down(&mlx->grid);
	draw_grid(&mlx->img, &mlx->grid, 0xFFFFFFFF);
//	draw_grid_points(&mlx->img, grid, 0xFFFFFFFF);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.ptr, 0, 0);
	recentre(&mlx->grid);
	return (-1);
}

int	close_window(t_mlx_data *mlx)
{
	mlx_destroy_image(mlx->ptr, mlx->img.ptr);
	mlx_destroy_window(mlx->ptr, mlx->win);
	mlx_destroy_display(mlx->ptr);
	free(mlx->ptr);
	free_file(mlx->file_elements);
	free_coords(&mlx->grid);
	exit(EXIT_SUCCESS);
}