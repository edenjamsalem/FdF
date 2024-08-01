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

bool within_screen(int x, int y)
{
	if (x > 0 && x < WIN_LEN && y > 0 && y < WIN_HEIGHT)
		return (true);
	return (false);
}