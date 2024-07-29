#include "FdF.h"

static void	draw_vertical_line(t_img *img, t_coord *start, t_coord *end, int colour)
{
	while (start->y <= end->y)
	{
		my_mlx_pixel_put(img, start, colour);
		start->y++;
	}
}

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
	{
		draw_vertical_line(img, start, end, colour);
		return ;
	}
	gradient = dy / dx;
	if (dy <= 0 && dx <= 0)
		draw_line_down(img, end, start, gradient, colour);
	else if (dx <= 0 || dy <= 0)
		draw_line_up(img, start, end, gradient, colour);
	else
		draw_line_down(img, start, end, gradient, colour);
}
/*
void	draw_line(t_img *img, t_coord *start, t_coord *end, int colour)
{
	int dx;
	int dy;
	int sx;
	int sy;
	int	e2;
	int	err;
	t_coord current;

	dx = abs((int)end->x - (int)start->x);
	dy = abs((int)end->y - (int)start->y);
	if (dx > dy)
		err = dx / 2;
	else
		err = -dy / 2;
	sx = 1;
	if (end->x <= start->x)
		sx = -1;
	sy = 1;
	if (end->y <= start->y)
		sy = -1;
	current.x = start->x;
	current.y = start->y;
	while (1)
	{
		my_mlx_pixel_put(img, &current, colour);
		if (current.x == end->x && current.y == end->y)
			break ;
		e2 = 2 * err;
        if (e2 > -dx) {
            err -= dy;
            current.x += sx;
        }
        if (e2 < dy) {
            err += dx;
            current.y += sy;
        }
	}	
}*/