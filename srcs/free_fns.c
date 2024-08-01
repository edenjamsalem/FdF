#include "../FdF.h"

void	malloc_error(t_mlx_data *mlx)
{
	free_mem(mlx);
	perror("Malloc Error");
	exit(EXIT_FAILURE);
}

void	free_file(char ***file_elements)
{
	int			i;
	int			j;
	
	i = 0;
	while (file_elements[i])
	{
		j = 0;
		while (file_elements[i][j])
			free(file_elements[i][j++]);
		free(file_elements[i]);
		i++;
	}
	free(file_elements);
}

void	free_coords(t_grid_data *grid)
{
	int 	i;
	int 	j;
	
	i = 0;
	while (i < grid->width)
	{
		j = 0;
		while (j < grid->len)
			free(grid->coords[i][j++]);
		free(grid->coords[i]);
		i++;
	}
	free(grid->coords);
}

void	free_mem(t_mlx_data *mlx)
{
	free(mlx->ptr);
	free_file(mlx->file_elements);
	free_coords(&mlx->grid);
}