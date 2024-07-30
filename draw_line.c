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

*/
void	increment_by_y(t_img *img, t_coord *start, t_coord *end, t_line *line, int colour)
{
	int		offset;
	double	delta;
	int		threshold;
	int		threshold_inc;

	delta = fabs(line->dx) * 2;
	threshold = fabs(line->dy);
	threshold_inc = fabs(line->dy) * 2;
	offset = 0;
	if (end->y < start->y)
	{
		ft_swap((int *)&end->x, (int *)&start->x);
		ft_swap((int *)&end->y, (int *)&start->y);
	}
	while (start->y <= end->y)
	{
		my_mlx_pixel_put(img, start, colour);
		offset += delta;
		if (offset >= threshold)
		{
			start->x += line->step;
			threshold += threshold_inc;
		}
		start->y++;
	}
}
void	increment_by_x(t_img *img, t_coord *start, t_coord *end, t_line *line, int colour)
{
	int		offset;
	double	delta;
	int		threshold;
	int		threshold_inc;

	delta = fabs(line->dy) * 2;
	threshold = fabs(line->dx);
	threshold_inc = fabs(line->dx) * 2;
	offset = 0;
	if (end->x < start->x)
	{
		ft_swap((int *)&end->x, (int *)&start->x);
		ft_swap((int *)&end->y, (int *)&start->y);
	}
	while (start->x <= end->x)
	{
		my_mlx_pixel_put(img, start, colour);
		offset += delta;
		if (offset >= threshold)
		{
			start->y += line->step;
			threshold += threshold_inc;
		}
		start->x++;
	}
}

void	draw_line(t_img *img, t_coord *start, t_coord *end, int colour)
{
	t_line	line;

	line.dx = end->x - start->x;	
	line.dy = end->y - start->y;	
	line.gradient = (float)line.dy / (float)line.dx;
	line.step = 1;
	if (line.gradient < 0)
		line.step = -1;
	if (line.gradient >= -1 && line.gradient <= 1)
		increment_by_x(img, start, end, &line, colour);
	else
		increment_by_y(img, start, end, &line, colour);
}
