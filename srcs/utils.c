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

void	recentre_img(t_grid_data *grid)
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

void	clear_img(t_mlx_data *mlx)
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

