#include "FdF.h"

static void	draw_vertical_line(t_img *img, t_coord *start, t_coord *end, int colour)
{
	while (start->y <= end->y)
	{
		my_mlx_pixel_put(img, start, colour);
		start->y++;
	}
}

static void	draw_line_up(t_img *img, t_coord *start, t_coord *end, int colour)
{
	float		gradient;
	float		dx;
	float		dy;
	float		i;

	dx = (float)(end->x - start->x);
	dy = (float)(end->y - start->y);
	if (dx == 0)
		draw_vertical_line(img, end, start, colour);
	else
	{
		gradient = dy / dx;
		i = gradient;
		while (start->x <= end->x && start->y >= end->y)
		{
			while (i > 1)
			{
				my_mlx_pixel_put(img, start, colour);
				start->y--;
				i--;
			}
			my_mlx_pixel_put(img, start, colour);
			start->x++;
			i += gradient;
		}
	}
}

static void	draw_line_down(t_img *img, t_coord *start, t_coord *end, int colour)
{
	float		gradient;
	float		dx;
	float		dy;
	float		i;

	dx = (float)(end->x - start->x);
	dy = (float)(end->y - start->y);
	if (dx == 0)
		draw_vertical_line(img, start, end, colour);
	else
	{
		gradient = dy / dx;
		i = gradient;
		while (start->x <= end->x && start->y <= end->y)
		{
			while (i > 1)
			{
				my_mlx_pixel_put(img, start, colour);
				start->y++;
				i--;
			}
			my_mlx_pixel_put(img, start, colour);
			start->x++;
			i += gradient;
		}	
	}
}

void	draw_line(t_img *img, t_coord *start, t_coord *end, int colour)
{
	if ((end->y - start->y) <= 0 && (end->x - start->x) <= 0)
		draw_line_down(img, end, start, colour);
	else if ((end->y - start->y) <= 0)
		draw_line_up(img, start, end, colour);
	else if ((end->x - start->x) <= 0)
		draw_line_up(img, end, start, colour);
	else
		draw_line_down(img, start, end, colour);
}