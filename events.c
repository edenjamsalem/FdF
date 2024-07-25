#include "FdF.h"

int	key_event(int keysym, t_mlx_data *mlx)
{
	if (keysym == ESC_KEY)
		close_window(mlx);
	if (keysym == A_KEY)
		shift_left(mlx);
	if (keysym == D_KEY)
		shift_right(mlx);
	if (keysym == W_KEY)
		shift_up(mlx);
	if (keysym == S_KEY)
		shift_down(mlx);
/*	if (keysym == Z_KEY)
		zoom_in(mlx);
	if (keysym == X_KEY)
		zoom_out(mlx);
	if (keysym == UP_KEY)
		rotate_forward(mlx, &mlx->grid);	
	if (keysym == LEFT_KEY)
		rotate_left();	
	if (keysym == DOWN_KEY)
		rotate_down();	
	if (keysym == RIGHT_KEY)
		rotate_right();	*/
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