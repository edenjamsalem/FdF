#include "FdF.h"

void	zoom(t_grid_data *grid, float factor)
{
	int		i;
	int		j;
	float	x;
	float	y;
	float	scale;

	scale = 1.0f / factor;
	i = 0;
	while (i < grid->width)
	{
		j = 0;
		while (j < grid->len)
		{
			x =  (grid->coords[i][j]->x - grid->centre.x) * scale;
			y =  (grid->coords[i][j]->y - grid->centre.y) * scale;
			grid->coords[i][j]->x += x;
			grid->coords[i][j]->y += y;
			j++;
		}
		i++;
	}
}
