#include "FdF.h"

int mouse_event(int button, int x, int y, t_mlx_data *mlx)
{
	(void)x;
	(void)y;

	clear_image(mlx);
	if (button == SCROLL_UP)
		zoom(&mlx->grid, 64);
	if (button == SCROLL_DOWN)
		zoom(&mlx->grid, -64);
	find_centre(&mlx->grid);
	draw_model(&mlx->img, &mlx->grid, 0xFFFFFFFF);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.ptr, 0, 0);
	return (-1);
}

int	key_event(int keysym, t_mlx_data *mlx)
{
	clear_image(mlx);
	if (keysym == ESC_KEY)
		close_window(mlx);

	if (keysym == A_KEY)
		rot_z_axis(&mlx->grid, -2);	
	if (keysym == D_KEY)
		rot_z_axis(&mlx->grid, 2);
	if (keysym == W_KEY)
		rot_x_axis(&mlx->grid, 2);
	if (keysym == S_KEY)
		rot_x_axis(&mlx->grid, -2);
	if (keysym == Q_KEY)
		rot_y_axis(&mlx->grid, 2);
	if (keysym == E_KEY)
		rot_y_axis(&mlx->grid, -2);

	if (keysym == RIGHT_KEY)
		shift_x(&mlx->grid, 2);
	if (keysym == LEFT_KEY)
		shift_x(&mlx->grid, -2);
	if (keysym == UP_KEY)
		shift_y(&mlx->grid, -2);
	if (keysym == DOWN_KEY)
		shift_y(&mlx->grid, 2);

	find_centre(&mlx->grid);
	draw_model(&mlx->img, &mlx->grid, 0xFFFFFFFF);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.ptr, 0, 0);
	return (-1);
}
