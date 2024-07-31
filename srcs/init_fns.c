#include "../FdF.h"

void	init_mlx(t_mlx_data *mlx)
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

void	init_img(t_img *img, t_mlx_data *mlx)
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
		free(mlx->img.ptr);
		mlx_destroy_window(mlx->ptr, mlx->win);
		mlx_destroy_display(mlx->ptr);
		free(mlx->ptr);
		exit(EXIT_FAILURE);
	}
}

void	init_centre(t_grid_data *grid)
{
	int		i;
	int		j;
	double	sum_x;
	double	sum_y;
	double	sum_z;
	int		total;

	total = grid->width * grid->len;
	sum_x = sum_y = sum_z = 0;
	i = 0;
	while (i < grid->width)
	{
		j = 0;
		while (j < grid->len)
		{
			sum_x += grid->coords[i][j]->x;
			sum_y += grid->coords[i][j]->y;
			sum_z += grid->coords[i][j++]->z;
		}
		i++;
	}
	grid->centre.x = sum_x / total;
	grid->centre.y = sum_y / total;
	grid->centre.z = sum_z / total;
}

static void	init_grid_coords(t_grid_data *grid, char ***file_elements)
{
	int 	i;
	int 	j;
	float	box_len;
	float	box_width;
	
	box_len = (WIN_LEN / 2) / grid->len - 1;
	box_width = (WIN_HEIGHT / 2) / grid->width - 1;
	if (!(grid->coords = malloc(sizeof(t_coord **) * grid->width)))
		malloc_error();
	i = 0;
	while (i < grid->width)
	{
		if (!(grid->coords[i] = malloc(sizeof(t_coord *) * grid->len)))
			malloc_error();
		j = 0;
		while (j < grid->len)
		{
			if (!(grid->coords[i][j] = malloc(sizeof(t_coord))))
				malloc_error();
			grid->coords[i][j]->x = WIN_LEN / 4 + (box_len * j);
			grid->coords[i][j]->y = WIN_HEIGHT / 4 + (box_width * i);
			grid->coords[i][j]->z = convert_dec(file_elements[i][j]) * 4;
			j++;
		}
		i++;
	}
}

void	init_grid_data(t_grid_data *grid, char ***file_elements)
{
	grid->width = ft_2darr_len((void *)(file_elements)); 
	grid->len = ft_2darr_len((void *)(file_elements[0]));
	init_grid_coords(grid, file_elements);
	init_centre(grid);
	recentre(grid);
}