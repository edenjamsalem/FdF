/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_fns.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamsalem <eamsalem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:28:46 by eamsalem          #+#    #+#             */
/*   Updated: 2024/08/02 11:29:16 by eamsalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

void	recentre_img(t_grid_data *grid)
{
	t_coord	centre_screen;
	int		dx;
	int		dy;

	centre_screen.x = WIN_LEN / 2;
	centre_screen.y = WIN_HEIGHT / 2;
	dx = grid->centre.x - centre_screen.x;
	dy = grid->centre.y - centre_screen.y;
	shift('x', -dx, grid);
	shift('y', -dy, grid);
}

void	clear_img(t_mlx_data *mlx)
{
	int		x;
	int		y;
	char	*dst;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_LEN)
		{
			dst = find_offset(x, y, &mlx->img);
			*((unsigned int *)dst) = 0x00000000;
			x++;
		}
		y++;
	}
}

static void	normalize(t_coord *coord, t_scale *range)
{
	double	z_min;
	double	z_max;

	z_min = range->z_min;
	z_max = range->z_max;
	coord->x = (coord->x - range->x_min) / range->x_max - range->x_min;
	coord->y = (coord->y - range->y_min) / range->y_max - range->y_min;
	coord->z = (coord->z - range->z_min) / range->z_max - range->z_min;
}

void	scale_img(t_grid_data *grid)
{
	int	i;
	int	j;

	i = 0;
	while (i < grid->width)
	{
		j = 0;
		while (j < grid->len)
		{
			normalize(grid->coords[i][j], &grid->range);
			grid->coords[i][j]->x *= WIN_LEN / 2;
			grid->coords[i][j]->y *= WIN_HEIGHT / 2;
			grid->coords[i][j]->z *= 50;
			j++;
		}
		i++;
	}
}

void	find_img_centre(t_grid_data *grid)
{
	int		i;
	int		j;
	double	sum_x;
	double	sum_y;
	double	sum_z;

	sum_x = 0;
	sum_y = 0;
	sum_z = 0;
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
	grid->centre.x = sum_x / (grid->width * grid->len);
	grid->centre.y = sum_y / (grid->width * grid->len);
	grid->centre.z = sum_z / (grid->width * grid->len);
}