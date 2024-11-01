/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fns.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:29:46 by eamsalem          #+#    #+#             */
/*   Updated: 2024/09/25 18:38:25 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

void	init_mlx_data(t_mlx_data *mlx)
{
	mlx->ptr = mlx_init();
	if (!mlx->ptr)
		exit(EXIT_FAILURE);
	mlx->win = mlx_new_window(mlx->ptr, WIN_LEN, WIN_HEIGHT, "FdF");
	if (!mlx->win)
	{
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
		free(mlx->ptr);
		exit(EXIT_FAILURE);
	}
	img->addr = mlx_get_data_addr(mlx->img.ptr, &mlx->img.bpp, \
							&mlx->img.line_len, &mlx->img.endian);
	if (!img->addr)
	{
		mlx_destroy_window(mlx->ptr, mlx->win);
		free(mlx->img.ptr);
		free(mlx->ptr);
		exit(EXIT_FAILURE);
	}
}

void	init_grid_coords(t_grid_data *grid, t_mlx_data *mlx)
{
	int	i;
	int	j;

	grid->coords = malloc(sizeof(t_coord **) * grid->width);
	if (!grid->coords)
		malloc_error(mlx);
	i = 0;
	while (i < grid->width)
	{
		grid->coords[i] = malloc(sizeof(t_coord *) * grid->len);
		if (!grid->coords[i])
			malloc_error(mlx);
		j = 0;
		while (j < grid->len)
		{
			grid->coords[i][j] = malloc(sizeof(t_coord));
			if (!grid->coords[i][j])
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
	int	i;
	int	j;

	grid->range.x_min = 0;
	grid->range.x_max = grid->len;
	grid->range.y_min = 0;
	grid->range.y_max = grid->width;
	grid->range.z_min = grid->coords[0][0]->z;
	grid->range.z_max = grid->coords[0][0]->z;
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
