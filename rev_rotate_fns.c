#include "FdF.h"

void	rev_rot_x_axis(t_grid_data *grid)
{
	int	i;
	int	j;
	double y;
	double z;
	double new_y;
	double new_z;

	i = 0;
	while (i < grid->width)
	{
		j = 0;
		while (j < grid->len)
		{
			y = grid->coords[i][j]->y - grid->centre.y;
			z = grid->coords[i][j]->z - grid->centre.z;
			new_y = (y * cos(rad(1))) + (z * sin(rad(1)));
			new_z = -(y * sin(rad(1))) + (z * cos(rad(1)));
			grid->coords[i][j]->y =  new_y + grid->centre.y;
			grid->coords[i][j]->z =  new_z + grid->centre.z;
			j++;
		}
		i++;
	}
}

void	rev_rot_y_axis(t_grid_data *grid)
{
	int	i;
	int	j;
	double x;
	double z;
	double new_x;
	double new_z;

	i = 0;
	while (i < grid->width)
	{
		j = 0;
		while (j < grid->len)
		{
			x = grid->coords[i][j]->x - grid->centre.x;
			z = grid->coords[i][j]->z - grid->centre.z;
			new_x = (x * cos(rad(1))) - (z * sin(rad(1)));
			new_z = (x * sin(rad(1))) + (z * cos(rad(1)));
			grid->coords[i][j]->x =  new_x + grid->centre.x;
			grid->coords[i][j]->z =  new_z + grid->centre.z;
			j++;
		}
		i++;
	}
}

void	rev_rot_z_axis(t_grid_data *grid)
{
	int	i;
	int	j;
	double x;
	double y;
	double new_x;
	double new_y;

	i = 0;
	while (i < grid->width)
	{
		j = 0;
		while (j < grid->len)
		{
			x = grid->coords[i][j]->x - grid->centre.x;
			y = grid->coords[i][j]->y - grid->centre.y;
			new_x = (x * cos(rad(1))) + (y * sin(rad(1)));
			new_y = -(x * sin(rad(1))) + (y * cos(rad(1)));
			grid->coords[i][j]->x =  new_x + grid->centre.x;
			grid->coords[i][j]->y =  new_y + grid->centre.y;
			j++;
		}
		i++;
	}
}