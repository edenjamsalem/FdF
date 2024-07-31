#include "../FdF.h"

void	clear_image(t_mlx_data *mlx)
{
	int	x;
	int	y;
	char *dst;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_LEN)
		{
			dst = find_offset(x, y, &mlx->img);
			*((unsigned int *)dst) = 0x00000000;
			x++;
		}
		y++;
	}
}

int mouse_event(int button, int x, int y, t_mlx_data *mlx)
{
	(void)x;
	(void)y;

	clear_image(mlx);
	if (button == SCROLL_UP)
		zoom(&mlx->grid, 20);
	if (button == SCROLL_DOWN)
		zoom(&mlx->grid, -20);
	draw_model(mlx, 0xFFFFFFFF);
	return (-1);
}

int	key_event(int keysym, t_mlx_data *mlx)
{
	clear_image(mlx);
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
		shift('x', 2, &mlx->grid);
	if (keysym == LEFT_KEY)
		shift('x', -2, &mlx->grid);
	if (keysym == UP_KEY)
		shift('y', -2, &mlx->grid);
	if (keysym == DOWN_KEY)
		shift('y', 2, &mlx->grid);
	draw_model(mlx, 0xFFFFFFFF);
	return (0);
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