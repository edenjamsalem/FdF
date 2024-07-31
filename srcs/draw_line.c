#include "../FdF.h"

static bool within_screen(int x, int y)
{
	if (x > 0 && x < WIN_LEN && y > 0 && y < WIN_HEIGHT)
		return (true);
	return (false);
}

void	put_pixel(t_img *img, t_coord *coord)
{
	char	*dst;

	if (within_screen(coord->x, coord->y))
	{
		dst = find_offset(coord->x, coord->y, img);
		*((unsigned int *)dst) = 0xFF800080;
	}
}

static void	increment_by_y(t_img *img, t_coord *start, t_coord *end, t_line *line)
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
		put_pixel(img, start);
		offset += delta;
		if (offset >= threshold)
		{
			start->x += line->step;
			threshold += threshold_inc;
		}
	}
}

static void	increment_by_x(t_img *img, t_coord *start, t_coord *end, t_line *line)
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
		put_pixel(img, start);
		offset += delta;
		if (offset >= threshold)
		{
			start->y += line->step;
			threshold += threshold_inc;
		}
	}
}

void	draw_line(t_img *img, t_coord *start, t_coord *end)
{
	t_line	line;

	line.dx = end->x - start->x;	
	line.dy = end->y - start->y;	
	line.step = 1;
	if (!(line.dy < 0 && line.dx < 0) && (line.dx < 0 || line.dy < 0))
		line.step = -1;
	if (fabs(line.dx) > fabs(line.dy))
	{
		if (start->x < end->x)
			increment_by_x(img, start, end, &line);
		else
			increment_by_x(img, end, start, &line);
	}
	else
	{
		if (start->y < end->y)
			increment_by_y(img, start, end, &line);
		else
			increment_by_y(img, end, start, &line);
	}
}
