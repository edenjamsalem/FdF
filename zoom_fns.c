#include "FdF.h"

void	zoom(t_grid_data *grid, int factor)
{
	int		i;
	int		j;
	float	x;
	float	y;

	i = 0;
	while (i < grid->width)
	{
		j = 0;
		while (j < grid->len)
		{
			x =  (grid->coords[i][j]->x - grid->centre.x) / factor;
			y =  (grid->coords[i][j]->y - grid->centre.y) / factor;
			grid->coords[i][j]->x += x;
			grid->coords[i][j]->y += y;
			j++;
		}
		i++;
	}
}
