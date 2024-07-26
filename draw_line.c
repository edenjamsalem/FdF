#include "FdF.h"
/*
static void	draw_vertical_line(t_img *img, t_coord *start, t_coord *end, int colour)
{
	while (start->y <= end->y)
	{
		my_mlx_pixel_put(img, start, colour);
		start->y++;
	}
}
*/
static void	draw_line_up(t_img *img, t_coord *start, t_coord *end, double gradient, int colour)
{
	double		i;

	i = 0;
	while (start->x <= end->x && start->y >= end->y)
	{
		i += gradient;
		while (i-- > 1)
		{
			my_mlx_pixel_put(img, start, colour);
			start->y--;
		}
		my_mlx_pixel_put(img, start, colour);
		start->x++;
	}
}

static void	draw_line_down(t_img *img, t_coord *start, t_coord *end, double gradient, int colour)
{
	double		i;

	i = 0;
	while (start->x <= end->x && start->y <= end->y)
	{
		i += gradient;
		while (i-- > 1)
		{
			my_mlx_pixel_put(img, start, colour);
			start->y++;
		}
		my_mlx_pixel_put(img, start, colour);
		start->x++;
	}	
}

void	draw_line(t_img *img, t_coord *start, t_coord *end, int colour)
{
	double		dx;
	double		dy;
	double		gradient;

	dx = end->x - start->x;	
	dy = end->y - start->y;	
	if (dx == 0)
		gradient = dy;
	else
		gradient = dy / dx;
	if (dy <= 0 && dx <= 0)
		draw_line_down(img, end, start, gradient, colour);
	else if (dx <= 0 || dy <= 0)
		draw_line_up(img, start, end, gradient, colour);
	else
		draw_line_down(img, start, end, gradient, colour);
}