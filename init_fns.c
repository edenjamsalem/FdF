#include "FdF.h"

int init_mlx_data(t_mlx_data *mlx)
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

int	init_grid_coords(t_grid_data *grid)
{
	int 	i;
	int 	j;
	t_coord	*coord;
	
	grid->coords = malloc(sizeof(t_coord **) * grid->width);
	if (!grid->coords)
		return (0);
	i = 0;
	while (i < grid->width)
	{
		grid->coords[i] = malloc(sizeof(t_coord *) * grid->len);
		if (!grid->coords[i])
			return (0);
		j = 0;
		while (j < grid->len)
		{
			coord = malloc(sizeof(coord));
			coord->x = grid->start.x + (grid->box_width * j);
			coord->y = grid->start.y + (grid->box_len * i);
			grid->coords[i][j++] = coord;
		}
		i++;
	}
	return (1);
}

int	init_grid_data(t_grid_data *grid, char ***file_elements)
{
	grid->width = ft_2darr_len((void *)(file_elements)); 
	grid->len = ft_2darr_len((void *)(file_elements[0]));
	grid->box_len = ((WIN_LEN / 2) / grid->len);
	grid->box_width = ((WIN_LEN / 2) / grid->len);
	grid->start.x = ((WIN_LEN / 2) - (0.5 * grid->len * grid->box_len));
	grid->start.y = ((WIN_HEIGHT / 2) - (0.5 * grid->width * grid->box_width));
	if (!init_grid_coords(grid))
		return (0);
	return (1);
}