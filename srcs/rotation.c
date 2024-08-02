/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamsalem <eamsalem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:35:06 by eamsalem          #+#    #+#             */
/*   Updated: 2024/08/02 12:27:46 by eamsalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

void	rot_x_axis(int angle, t_coord *coord, t_coord *centre)
{
	double	y;
	double	z;
	double	cos_a;
	double	sin_a;

	cos_a = cos(rad(angle));
	sin_a = sin(rad(angle));
	y = coord->y - centre->y;
	z = coord->z - centre->z;
	coord->y = (y * cos_a) - (z * sin_a) + centre->y;
	coord->z = (y * sin_a) + (z * cos_a) + centre->z;
}

void	rot_y_axis(int angle, t_coord *coord, t_coord *centre)
{
	double	x;
	double	z;
	double	cos_a;
	double	sin_a;

	cos_a = cos(rad(angle));
	sin_a = sin(rad(angle));
	x = coord->x - centre->x;
	z = coord->z - centre->z;
	coord->x = (x * cos_a) + (z * sin_a) + centre->x;
	coord->z = -(x * sin_a) + (z * cos_a) + centre->z;
}

void	rot_z_axis(int angle, t_coord *coord, t_coord *centre)
{
	double	x;
	double	y;
	double	cos_a;
	double	sin_a;

	cos_a = cos(rad(angle));
	sin_a = sin(rad(angle));
	x = coord->x - centre->x;
	y = coord->y - centre->y;
	coord->x = (x * cos_a) - (y * sin_a) + centre->x;
	coord->y = (x * sin_a) + (y * cos_a) + centre->y;
}

void	rotate(char axis, int angle, t_grid_data *grid)
{
	int		i;
	int		j;

	i = 0;
	while (i < grid->width)
	{
		j = 0;
		while (j < grid->len)
		{
			if (axis == 'x')
				rot_x_axis(angle, grid->coords[i][j], &grid->centre);
			else if (axis == 'y')
				rot_y_axis(angle, grid->coords[i][j], &grid->centre);
			else if (axis == 'z')
				rot_z_axis(angle, grid->coords[i][j], &grid->centre);
			j++;
		}
		i++;
	}
}
