#include "FdF.h"

char *find_offset(int x, int y, t_img *img)
{
	return (img->addr + ((y * img->line_len) + (x * (img->bpp / 8))));
}

static bool within_screen(int x, int y)
{
	if (x > 0 && x < WIN_LEN && y > 0 && y < WIN_HEIGHT)
		return (true);
	return (false);
}

void	my_mlx_pixel_put(t_img *img, t_coord *coord, int colour)
{
	char	*dst;

	if (within_screen(coord->x, coord->y))
	{
		dst = find_offset(coord->x, coord->y, img);
		*((unsigned int *)dst) = colour;
	}
}