#include "../FdF.h"

int mouse_event(int button, int x, int y, t_mlx_data *mlx)
{
	(void)x;
	(void)y;

	clear_img(mlx);
	if (button == SCROLL_UP)
		zoom(&mlx->grid, 20);
	if (button == SCROLL_DOWN)
		zoom(&mlx->grid, -20);
	draw_model(mlx);
	return (-1);
}

int	key_event(int keysym, t_mlx_data *mlx)
{
	clear_img(mlx);
	if (keysym == ESC_KEY)
		close_window(mlx);
	if (keysym == A_KEY)
		rot_z_axis(-2, &mlx->grid);	
	if (keysym == D_KEY)
		rot_z_axis(2, &mlx->grid);	
	if (keysym == W_KEY)
		rot_x_axis(2, &mlx->grid);	
	if (keysym == S_KEY)
		rot_x_axis(-2, &mlx->grid);	
	if (keysym == Q_KEY)
		rot_y_axis(-2, &mlx->grid);	
	if (keysym == E_KEY)
		rot_y_axis(2, &mlx->grid);	
	if (keysym == RIGHT_KEY)
		shift('x', 4, &mlx->grid);
	if (keysym == LEFT_KEY)
		shift('x', -4, &mlx->grid);
	if (keysym == UP_KEY)
		shift('y', -4, &mlx->grid);
	if (keysym == DOWN_KEY)
		shift('y', 4, &mlx->grid);
	draw_model(mlx);
	return (0);
}

int	close_window(t_mlx_data *mlx)
{
	mlx_destroy_image(mlx->ptr, mlx->img.ptr);
	mlx_destroy_window(mlx->ptr, mlx->win);
	mlx_destroy_display(mlx->ptr);
	free_mem(mlx);
	exit(EXIT_SUCCESS);
}
