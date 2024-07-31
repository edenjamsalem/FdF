#include "FdF.h"

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