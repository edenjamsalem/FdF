#include "FdF.h"

void	rot_x_axis(t_grid_data *grid, int angle)
{
	int	i;
	int	j;
	double y;
	double z;
	double cos_a;
	double sin_a;

	cos_a = cos(rad(angle));
	sin_a = sin(rad(angle));
	i = 0;
	while (i < grid->width)
	{
		j = 0;
		while (j < grid->len)
		{
			y = grid->coords[i][j]->y - grid->centre.y;
			z = grid->coords[i][j]->z - grid->centre.z;
			grid->coords[i][j]->y =  (y * cos_a) - (z * sin_a) + grid->centre.y;
			grid->coords[i][j]->z =  (y * sin_a) + (z * cos_a) + grid->centre.z;
			j++;
		}
		i++;
	}
}

void	rot_y_axis(t_grid_data *grid, int angle)
{
	int	i;
	int	j;
	double x;
	double z;
	double cos_a;
	double sin_a;

	cos_a = cos(rad(angle));
	sin_a = sin(rad(angle));
	i = 0;
	while (i < grid->width)
	{
		j = 0;
		while (j < grid->len)
		{
			x = grid->coords[i][j]->x - grid->centre.x;
			z = grid->coords[i][j]->z - grid->centre.z;
			grid->coords[i][j]->x =  (x * cos_a) + (z * sin_a) + grid->centre.x;
			grid->coords[i][j]->z =  -(x * sin_a) + (z * cos_a) + grid->centre.z;
			j++;
		}
		i++;
	}
}

void	rot_z_axis(t_grid_data *grid, int angle)
{
	int	i;
	int	j;
	double x;
	double y;
	double cos_a;
	double sin_a;

	cos_a = cos(rad(angle));
	sin_a = sin(rad(angle));
	i = 0;
	while (i < grid->width)
	{
		j = 0;
		while (j < grid->len)
		{
			x = grid->coords[i][j]->x - grid->centre.x;
			y = grid->coords[i][j]->y - grid->centre.y;
			grid->coords[i][j]->x =  (x * cos_a) - (y * sin_a) + grid->centre.x;
			grid->coords[i][j]->y =  (x * sin_a) + (y * cos_a) + grid->centre.y;
			j++;
		}
		i++;
	}
}
