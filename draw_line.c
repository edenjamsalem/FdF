#include "FdF.h"

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
	while (start->y <= end->y)
	{
		start->y++;
		my_mlx_pixel_put(img, start, colour);
		offset += delta;
		if (offset >= threshold)
		{
			start->x += line->step;
			threshold += threshold_inc;
		}
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
	while (start->x <= end->x)
	{
		start->x++;
		my_mlx_pixel_put(img, start, colour);
		offset += delta;
		if (offset >= threshold)
		{
			start->y += line->step;
			threshold += threshold_inc;
		}
	}
}

void	draw_line(t_img *img, t_coord *start, t_coord *end, int colour)
{
	t_line	line;

	line.dx = end->x - start->x;	
	line.dy = end->y - start->y;	
	line.gradient = line.dy / line.dx;
	line.step = 1;
	if (line.gradient < 0)
		line.step = -1;
	if (line.gradient >= -1 && line.gradient <= 1)
	{
		if (start->x < end->x)
			increment_by_x(img, start, end, &line, colour);
		else
			increment_by_x(img, end, start, &line, colour);
	}
	else
	{
		if (start->y < end->y)
			increment_by_y(img, start, end, &line, colour);
		else
			increment_by_y(img, end, start, &line, colour);
	}
}
