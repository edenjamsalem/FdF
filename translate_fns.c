#include "FdF.h"

void	shift_left(t_grid_data *grid)
{
	int	i;
	int j;

	i = 0;
	while (i < grid->width)
	{
		j = 0;
		while (j < grid->len)
			grid->coords[i][j++]->x -= 2;
		i++;
	}
}

void	shift_right(t_grid_data *grid)
{
	int	i;
	int j;

	i = 0;
	while (i < grid->width)
	{
		j = 0;
		while (j < grid->len)
			grid->coords[i][j++]->x += 2;
		i++;
	}
}

void	shift_up(t_grid_data *grid)
{
	int	i;
	int j;

	i = 0;
	while (i < grid->width)
	{
		j = 0;
		while (j < grid->len)
			grid->coords[i][j++]->y -= 2;
		i++;
	}
}

void	shift_down(t_grid_data *grid)
{
	int	i;
	int j;

	i = 0;
	while (i < grid->width)
	{
		j = 0;
		while (j < grid->len)
			grid->coords[i][j++]->y += 2;
		i++;
	}
}