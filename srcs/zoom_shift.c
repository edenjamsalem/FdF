#include "../FdF.h"

void	shift_x(int step, t_grid_data *grid)
{
	int	i;
	int	j;

	i = 0;
	while (i < grid->width)
	{
		j = 0;
		while (j < grid->len)
			grid->coords[i][j++]->x += step;
		i++;
	}
}

void	shift_y(int step, t_grid_data *grid)
{
	int	i;
	int	j;

	i = 0;
	while (i < grid->width)
	{
		j = 0;
		while (j < grid->len)
			grid->coords[i][j++]->y += step;
		i++;
	}
}

void	zoom(t_grid_data *grid, double factor)
{
	int		i;
	int		j;
	double	x;
	double	y;
	double	scale;

	scale = 1.0 / factor;
	i = 0;
	while (i < grid->width)
	{
		j = 0;
		while (j < grid->len)
		{
			x = (grid->coords[i][j]->x - grid->centre.x) * scale;
			y = (grid->coords[i][j]->y - grid->centre.y) * scale;
			grid->coords[i][j]->x += x;
			grid->coords[i][j]->y += y;
			j++;
		}
		i++;
	}
}