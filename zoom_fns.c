#include "FdF.h"

void	zoom_in(t_grid_data *grid)
{
	int		i;
	int		j;
	double	x;
	double	y;

	i = 0;
	while (i < grid->width)
	{
		j = 0;
		while (j < grid->len)
		{
			x =  (grid->coords[i][j]->x - grid->centre.x) / 50;
			y =  (grid->coords[i][j]->y - grid->centre.y) / 50;
			grid->coords[i][j]->x += x;
			grid->coords[i][j]->y += y;
			j++;
		}
		i++;
	}
}

void	zoom_out(t_grid_data *grid)
{
	int		i;
	int		j;
	double	x;
	double	y;

	i = 0;
	while (i < grid->width)
	{
		j = 0;
		while (j < grid->len)
		{
			x =  (grid->coords[i][j]->x - grid->centre.x) / 50;
			y =  (grid->coords[i][j]->y - grid->centre.y) / 50;
			grid->coords[i][j]->x -= x;
			grid->coords[i][j]->y -= y;
			j++;
		}
		i++;
	}
}
