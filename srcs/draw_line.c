#include "../FdF.h"

static void	put_pixel(t_img *img, t_coord *coord, int colour)
{
	char	*dst;

	if (within_screen(coord->x, coord->y))
	{
		dst = find_offset(coord->x, coord->y, img);
		*((unsigned int *)dst) = colour;
	}
}

static void	inc_by_y(t_img *img, t_coord *start, t_coord *end, t_line *line)
{
	int			offset;
	double		delta;
	int			threshold;
	int			threshold_inc;
	int			step_count;
	int			total_steps;
	t_colour	colour;
	float		t;

	delta = fabs(line->dx) * 2;
	threshold = fabs(line->dy);
	threshold_inc = fabs(line->dy) * 2;
	total_steps = end->y - start->y;
	step_count = 0;
	offset = 0;
	while (start->y <= end->y)
	{
		t = (float)step_count / (float)total_steps;
		colour = terp_colour(start->colour, end->colour, t);
		put_pixel(img, start, rgb_to_hex(colour));
		offset += delta;
		if (offset >= threshold)
		{
			start->x += line->step;
			threshold += threshold_inc;
		}
		start->y++;
		step_count++;
	}
}

static void	inc_by_x(t_img *img, t_coord *start, t_coord *end, t_line *line)
{
	int			offset;
	double		delta;
	int			threshold;
	int			threshold_inc;
	int			step_count;
	int			total_steps;
	t_colour	colour;
	float		t;
	
	delta = fabs(line->dy) * 2;
	threshold = fabs(line->dx);
	threshold_inc = fabs(line->dx) * 2;
	total_steps = end->x - start->x;
	step_count = 0;
	offset = 0;
	while (start->x <= end->x)
	{
		t =  (float)step_count / (float)total_steps;
		colour = terp_colour(start->colour, end->colour, t);
		put_pixel(img, start, rgb_to_hex(colour));
		offset += delta;
		if (offset >= threshold)
		{
			start->y += line->step;
			threshold += threshold_inc;
		}
		start->x++;
		step_count++;
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
			inc_by_x(img, start, end, &line);
		else
			inc_by_x(img, end, start, &line);
	}
	else
	{
		if (start->y < end->y)
			inc_by_y(img, start, end, &line);
		else
			inc_by_y(img, end, start, &line);
	}
}
