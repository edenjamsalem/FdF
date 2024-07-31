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

float	rad(float degrees)
{
	return (degrees * (PI / 180));
}

void	recentre(t_grid_data *grid)
{
	t_coord centre_screen;
	int		dx;
	int		dy;

	centre_screen.x = WIN_LEN / 2;
	centre_screen.y = WIN_HEIGHT / 2;
	dx = grid->centre.x - centre_screen.x;
	dy = grid->centre.y - centre_screen.y;
	shift_x(grid, -dx);	
	shift_y(grid, -dy);	
}

void	find_centre(t_grid_data *grid)
{
	int		i;
	int		j;
	float	sum_x;
	float	sum_y;
	float	sum_z;
	int		total;

	sum_x = 0;
	sum_y = 0;
	sum_z = 0;
	total = grid->width * grid->len;
	i = 0;
	while (i < grid->width)
	{
		j = 0;
		while (j < grid->len)
		{
			sum_x += grid->coords[i][j]->x;
			sum_y += grid->coords[i][j]->y;
			sum_z += grid->coords[i][j++]->z;
		}
		i++;
	}
	grid->centre.x = sum_x / total;
	grid->centre.y = sum_y / total;
	grid->centre.z = sum_z / total;
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

void	clear_image(t_mlx_data *mlx)
{
	int	x;
	int	y;
	char *dst;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_LEN)
		{
			dst = find_offset(x, y, &mlx->img);
			*((unsigned int *)dst) = 0x00000000;
			x++;
		}
		y++;
	}
}