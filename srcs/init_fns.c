#include "../FdF.h"

void	init_mlx_data(t_mlx_data *mlx)
{
	if (!(mlx->ptr = mlx_init()))
		exit(EXIT_FAILURE);
	mlx->win = mlx_new_window(mlx->ptr, WIN_LEN, WIN_HEIGHT, "FdF");
	if (!mlx->win)
	{
		mlx_destroy_display(mlx->ptr);
		free(mlx->ptr);
		exit(EXIT_FAILURE);
	}
}

void	init_img_data(t_img *img, t_mlx_data *mlx)
{
	img->ptr = mlx_new_image(mlx->ptr, WIN_LEN, WIN_HEIGHT);
	if (!img->ptr)
	{
		mlx_destroy_window(mlx->ptr, mlx->win);
		mlx_destroy_display(mlx->ptr);
		free(mlx->ptr);
		exit(EXIT_FAILURE);
	}
	img->addr = mlx_get_data_addr(mlx->img.ptr, &mlx->img.bpp, \
							&mlx->img.line_len, &mlx->img.endian);
	if (!img->addr)
	{
		mlx_destroy_window(mlx->ptr, mlx->win);
		mlx_destroy_display(mlx->ptr);
		free(mlx->img.ptr);
		free(mlx->ptr);
		exit(EXIT_FAILURE);
	}
}

static void	init_grid_coords(t_grid_data *grid, t_mlx_data *mlx)
{
	int 	i;
	int 	j;
	
	if (!(grid->coords = malloc(sizeof(t_coord **) * grid->width)))
		malloc_error(mlx);
	i = 0;
	while (i < grid->width)
	{
		if (!(grid->coords[i] = malloc(sizeof(t_coord *) * grid->len)))
			malloc_error(mlx);
		j = 0;
		while (j < grid->len)
		{
			if (!(grid->coords[i][j] = malloc(sizeof(t_coord))))
				malloc_error(mlx);
			grid->coords[i][j]->x = j;
			grid->coords[i][j]->y = i;
			grid->coords[i][j]->z = convert_dec(mlx->file_data[i][j]);
			j++;
		}
		i++;
	}
}

void	init_grid_scale(t_grid_data *grid)
{
	int i;
	int j;

	grid->range.x_min = 0;
	grid->range.x_max = grid->len;
	grid->range.y_min = 0;
	grid->range.y_max = grid->width;
	grid->range.z_min = grid->range.z_max = grid->coords[0][0]->z;
	i = 0;
	while (i < grid->width)
	{
		j = 0;
		while (j < grid->len)
		{
			if (grid->coords[i][j]->z < grid->range.z_min)
				grid->range.z_min = grid->coords[i][j]->z;
			if (grid->coords[i][j]->z > grid->range.z_max)
				grid->range.z_max = grid->coords[i][j]->z;
			j++;
		}
		i++;
	}
}

float	find_t(double z, t_grid_data *grid)
{
	double z_min;
	double z_max;

	z_min = grid->range.z_min;
	z_max = grid->range.z_max;
	return ((z - z_min) / (z_max - z_min));
}

void	init_grid_colours(t_grid_data *grid)
{
	t_colour	base;
	t_colour	top;
	float		t;
	int			i;
	int			j;

	base = hex_to_rgb(WHITE);
	top = hex_to_rgb(PURPLE);
	i = 0;
	while (i < grid->width)
	{
		j = 0;
		while (j < grid->len)
		{
			t = find_t(grid->coords[i][j]->z, grid);
			grid->coords[i][j]->colour = terp_colour(base, top, t);
			j++;
		}
		i++;
	}
}

void	init_grid_data(t_mlx_data *mlx)
{
	mlx->grid.width = ft_2darr_len((void *)(mlx->file_data)); 
	mlx->grid.len = ft_2darr_len((void *)(mlx->file_data[0]));
	init_grid_coords(&mlx->grid, mlx);
	init_grid_scale(&mlx->grid);
	init_grid_colours(&mlx->grid);
	scale_img(&mlx->grid);
	find_img_centre(&mlx->grid);
	recentre_img(&mlx->grid);
}
