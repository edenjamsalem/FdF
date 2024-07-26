#include "FdF.h"

static void	draw_horizontal_lines(t_img *img, t_grid_data *grid, int colour)
{
	int 	i;
	int 	j;
	t_coord	start;
	t_coord	next;
	
	i = 0;
	while (i < grid->width)
	{
		j = 0;
		while (j < grid->len - 1)
		{
			start.x = grid->coords[i][j]->x;
			start.y = grid->coords[i][j]->y;
			next.x = grid->coords[i][j + 1]->x;
			next.y = grid->coords[i][j + 1]->y;
			draw_line(img, &start, &next, colour);
			j++;
		}
		i++;
	}
}

static void	draw_vertical_lines(t_img *img, t_grid_data *grid, int colour)
{
	int 	i;
	int 	j;
	t_coord	start;
	t_coord	next;
	
	j = 0;
	while (j < grid->len)
	{
		i = 0;
		while (i < grid->width - 1)
		{
			start.x = grid->coords[i][j]->x;
			start.y = grid->coords[i][j]->y;
			next.x = grid->coords[i + 1][j]->x;
			next.y = grid->coords[i + 1][j]->y;
			draw_line(img, &start, &next, colour);
			i++;
		}
		j++;
	}
}

void	draw_grid(t_img *img, t_grid_data *grid, int colour)
{
	draw_horizontal_lines(img, grid, colour);
	draw_vertical_lines(img, grid, colour);
}

void draw_grid_points(t_img *img, t_grid_data *grid, int colour)
{
	int 	i;
	int 	j;
	t_coord	start;
	
	j = 0;
	while (j < grid->len)
	{
		i = 0;
		while (i < grid->width)
		{
			start.x = grid->coords[i][j]->x;
			start.y = grid->coords[i][j]->y;
			my_mlx_pixel_put(img, &start, colour);
			i++;
		}
		j++;
	}
}