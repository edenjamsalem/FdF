/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_model.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamsalem <eamsalem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 10:44:51 by eamsalem          #+#    #+#             */
/*   Updated: 2024/08/02 12:21:16 by eamsalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

static void	draw_horizontal_lines(t_img *img, t_grid_data *grid)
{
	int		i;
	int		j;
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
			draw_line(img, &start, &next);
			j++;
		}
		i++;
	}
}

static void	draw_vertical_lines(t_img *img, t_grid_data *grid)
{
	int		i;
	int		j;
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
			draw_line(img, &start, &next);
			i++;
		}
		j++;
	}
}

void	draw_model(t_mlx_data *mlx)
{
	draw_horizontal_lines(&mlx->img, &mlx->grid);
	draw_vertical_lines(&mlx->img, &mlx->grid);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.ptr, 0, 0);
	find_img_centre(&mlx->grid);
}
