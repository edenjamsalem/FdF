#include "FdF.h"

void	shift_x(t_grid_data *grid, int step)
{
	int	i;
	int j;

	i = 0;
	while (i < grid->width)
	{
		j = 0;
		while (j < grid->len)
			grid->coords[i][j++]->x += step;
		i++;
	}
}

void	shift_y(t_grid_data *grid, int step)
{
	int	i;
	int j;

	i = 0;
	while (i < grid->width)
	{
		j = 0;
		while (j < grid->len)
			grid->coords[i][j++]->y += step;
		i++;
	}
}
