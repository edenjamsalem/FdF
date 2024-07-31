#include "FdF.h"

void	free_file(char ***file_elements)
{
	int			i;
	int			j;
	
	i = 0;
	while (file_elements[i])
	{
		j = 0;
		while (file_elements[i][j])
			free(file_elements[i][j++]);
		free(file_elements[i]);
		i++;
	}
	free(file_elements);
}

void	free_coords(t_grid_data *grid)
{
	int 	i;
	int 	j;
	
	i = 0;
	while (i < grid->width)
	{
		j = 0;
		while (j < grid->len)
			free(grid->coords[i][j++]);
		free(grid->coords[i]);
		i++;
	}
	free(grid->coords);
}

void	print_file(char ***file_elements)
{
	int			i;
	int			j;
	
	i = -1;
	while (file_elements[i])
	{
		j = -1;
		while (file_elements[i][j])
			ft_printf("%s ", file_elements[i][j++]);
		ft_printf("\n");
		i++;
	}
}

float	rad(float degrees)
{
	return (degrees * (PI / 180));
}

void	find_centre(t_grid_data *grid)
{
	int		i;
	int		j;
	float	sum_z;
	float	x;
	float	y;
	float	x_end;
	float	y_end;

	x = grid->coords[0][0]->x;
	y = grid->coords[0][0]->y;
	x_end = grid->coords[grid->width - 1][grid->len - 1]->x;
	y_end = grid->coords[grid->width - 1][grid->len - 1]->y;
	grid->centre.x = (x + x_end) / 2;
	grid->centre.y = (y + y_end) / 2;
	sum_z = 0;
	i = 0;
	while (i < grid->width)
	{
		j = 0;
		while (j < grid->len)
			sum_z += grid->coords[i][j++]->z;
		i++;
	}
	grid->centre.z = sum_z / (grid->width * grid->len);
}

void	isometric_projection(t_grid_data *grid)
{
	rot_x_axis(grid, 30);
	rot_y_axis(grid, -30);
	rot_z_axis(grid, 30);
}

float convert_dec(char *nbr)
{
	if (!nbr)
		return (0);
	if (ft_strncmp(nbr, "0x", 2) == 0)
		return ((float)ft_atoi_base(nbr, "0x123456789ABCDEF"));
	return ((float)ft_atoi(nbr));
}
