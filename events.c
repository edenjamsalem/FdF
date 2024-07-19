#include "FdF.h"

int	key_event(int keysym, t_mlx_data *mlx)
{
	if (keysym == ESC_KEY)
	{
		mlx_destroy_image(mlx->ptr, mlx->img.ptr);
		mlx_destroy_window(mlx->ptr, mlx->win);
		mlx_destroy_display(mlx->ptr);
		free(mlx->ptr);
		free_file(mlx->file_elements);
		exit(EXIT_SUCCESS);
	}
	return (-1);
}

int	close_window(t_mlx_data *mlx)
{
	mlx_destroy_image(mlx->ptr, mlx->img.ptr);
	mlx_destroy_window(mlx->ptr, mlx->win);
	mlx_destroy_display(mlx->ptr);
	free(mlx->ptr);
	exit(EXIT_SUCCESS);
}