/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_fns.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:27:17 by eamsalem          #+#    #+#             */
/*   Updated: 2024/09/25 18:38:41 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

void	malloc_error(t_mlx_data *mlx)
{
	free_mem(mlx);
	perror("Malloc Error");
	exit(EXIT_FAILURE);
}

void	free_file(char ***file_data)
{
	int	i;
	int	j;

	i = 0;
	while (file_data[i])
	{
		j = 0;
		while (file_data[i][j])
			free(file_data[i][j++]);
		free(file_data[i]);
		i++;
	}
	free(file_data);
}

void	free_coords(t_grid_data *grid)
{
	int	i;
	int	j;

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
	mlx_destroy_image(mlx->ptr, mlx->img.ptr);
	mlx_destroy_window(mlx->ptr, mlx->win);
	free_file(mlx->file_data);
	free_coords(&mlx->grid);
	free(mlx->ptr);
}
