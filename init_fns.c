#include "FdF.h"

int init_mlx_win(t_mlx_data *mlx)
{
	mlx->win = mlx_new_window(mlx->ptr, WIN_LEN, WIN_HEIGHT, "FdF");
	if (!mlx->win)
	{
		mlx_destroy_display(mlx->ptr);
		free(mlx->ptr);
		return (0);
	}
	return (1);	
}

int	init_img(t_img *img, t_mlx_data *mlx)
{
	img->ptr = mlx_new_image(mlx->ptr, WIN_LEN, WIN_HEIGHT);
	if (!img->ptr)
	{
		mlx_destroy_window(mlx->ptr, mlx->win);
		mlx_destroy_display(mlx->ptr);
		free(mlx->ptr);
		return (0);
	}
	img->addr = mlx_get_data_addr(mlx->img.ptr, &mlx->img.bpp, \
							&mlx->img.line_len, &mlx->img.endian);
	if (!img->addr)
	{
		free(mlx->img.ptr);
		mlx_destroy_window(mlx->ptr, mlx->win);
		mlx_destroy_display(mlx->ptr);
		free(mlx->ptr);
		return (0);
	}
	return (1);
}

int	init_grid_coords(t_grid_data *grid, char ***file_elements)
{
	int 	i;
	int 	j;
	double	box_len;
	double	box_width;
	
	box_len = (WIN_LEN / 2) / grid->len - 1;
	box_width = (WIN_HEIGHT / 2) / grid->width - 1;
	if (!(grid->coords = malloc(sizeof(t_coord **) * grid->width)))
		return (0);
	i = 0;
	while (i < grid->width)
	{
		if (!(grid->coords[i] = malloc(sizeof(t_coord *) * grid->len)))
			return (0);
		j = 0;
		while (j < grid->len)
		{
			if (!(grid->coords[i][j] = malloc(sizeof(t_coord))))
				return (0);
			grid->coords[i][j]->x = WIN_LEN / 4 + (box_len * j);
			grid->coords[i][j]->y = WIN_HEIGHT / 4 + (box_width * i);
			grid->coords[i][j]->z = ft_atoi(file_elements[i][j]) * 2;
			j++;
		}
		i++;
	}
	return (1);
}

void	isometric_projection(t_grid_data *grid)
{
	rot_x_axis(grid, 30);
	rot_y_axis(grid, -30);
	rot_z_axis(grid, 30);
}

int	init_grid_data(t_grid_data *grid, char ***file_elements)
{
	grid->width = ft_2darr_len((void *)(file_elements)); 
	grid->len = ft_2darr_len((void *)(file_elements[0]));
	if (!init_grid_coords(grid, file_elements))
		return (0);
	recentre(grid);
	isometric_projection(grid);
	return (1);
}