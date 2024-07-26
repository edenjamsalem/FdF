#include "FdF.h"

int	key_event(int keysym, t_mlx_data *mlx)
{
	if (keysym == ESC_KEY)
		close_window(mlx);
	if (keysym == A_KEY)
		rev_rot_z_axis(mlx, &mlx->grid);	
	if (keysym == D_KEY)
		rot_z_axis(mlx, &mlx->grid);
	if (keysym == W_KEY)
		rot_x_axis(mlx, &mlx->grid);
//	if (keysym == S_KEY)
	if (keysym == Z_KEY)
		zoom_in(mlx, &mlx->grid);
	if (keysym == X_KEY)
		zoom_out(mlx, &mlx->grid);
	if (keysym == RIGHT_KEY)
		shift_right(mlx);
	if (keysym == LEFT_KEY)
		shift_left(mlx);
	if (keysym == UP_KEY)
		shift_up(mlx);
	if (keysym == DOWN_KEY)
		shift_down(mlx);
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
	free(mlx->grid.centre);
	exit(EXIT_SUCCESS);
}