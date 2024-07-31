#include "../FdF.h"

void	isometric_projection(t_grid_data *grid)
{
	rot_x_axis(30, grid);
	rot_y_axis(-30, grid);
	rot_z_axis(30, grid);
}

static void	draw_horizontal_lines(t_img *img, t_grid_data *grid, int colour)
{
	int 	i;
	int 	j;
	t_coord	start;
	t_coord	next;
	
	i = 0;
	while (i < grid->width)
	{
		j = 0;
		while (j < grid->len - 1)
		{
			start.x = grid->coords[i][j]->x;
			start.y = grid->coords[i][j]->y;
			next.x = grid->coords[i][j + 1]->x;
			next.y = grid->coords[i][j + 1]->y;
			draw_line(img, &start, &next, colour);
			j++;
		}
		i++;
	}
}

static void	draw_vertical_lines(t_img *img, t_grid_data *grid, int colour)
{
	int 	i;
	int 	j;
	t_coord	start;
	t_coord	next;
	
	j = 0;
	while (j < grid->len)
	{
		i = 0;
		while (i < grid->width - 1)
		{
			start.x = grid->coords[i][j]->x;
			start.y = grid->coords[i][j]->y;
			next.x = grid->coords[i + 1][j]->x;
			next.y = grid->coords[i + 1][j]->y;
			draw_line(img, &start, &next, colour);
			i++;
		}
		j++;
	}
}

void	draw_model(t_mlx_data *mlx, int colour)
{
	draw_horizontal_lines(&mlx->img, &mlx->grid, colour);
	draw_vertical_lines(&mlx->img, &mlx->grid, colour);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.ptr, 0, 0);
	init_centre(&mlx->grid);
}
