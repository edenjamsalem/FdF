#include "../FdF.h"

double	rad(double degrees)
{
	return (degrees * (PI / 180));
}

char *find_offset(int x, int y, t_img *img)
{
	return (img->addr + ((y * img->line_len) + (x * (img->bpp / 8))));
}

double convert_dec(char *nbr)
{
	if (!nbr)
		return (0);
	if (ft_strncmp(nbr, "0x", 2) == 0)
		return ((double)ft_atoi_base(nbr, "0x123456789ABCDEF"));
	return ((double)ft_atoi(nbr));
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
	shift('x', -dx, grid);	
	shift('y', -dy, grid);	
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
