#include "FdF.h"

void colour_background(t_img img, int colour)
{
	t_coord coord;

	coord.y = 0;
	while (coord.y < WIN_HEIGHT)
	{	
		coord.x = 0;
		while (coord.x < WIN_LEN)
			my_mlx_pixel_put(&img, coord, colour);
		coord.y++;
	}
}

int	gradient_shallow(t_coord start, t_coord end)
{
	return ((end.y - start.y) / (end.x - start.x));
}
void	draw_both_negative(t_img *img, t_coord start, t_coord end, int colour)
{
	int		gradient;
	int		i;
	
	gradient = abs((end.y - start.y) / (end.x - start.x));
	if (!gradient)
		gradient = abs((end.x - start.x) / (end.y - start.y));
	while (start.x > end.x && start.y > end.y)
	{
		i = 0;
		while (i < gradient)
		{
			my_mlx_pixel_put(img, start, colour);
			if (gradient_shallow(start, end))
				start.y--;
			else 
				start.x--;
			i++;
		}
		if (gradient_shallow(start, end))
			start.x--;
		else
			start.y--;
	}
}

void	draw_y_negative(t_img *img, t_coord start, t_coord end, int colour)
{
	int		gradient;
	int		i;
	
	gradient = abs((end.y - start.y) / (end.x - start.x));
	if (!gradient)
		gradient = abs((end.x - start.x) / (end.y - start.y));
	while (start.x < end.x && start.y > end.y)
	{
		i = 0;
		while (i < gradient)
		{
			my_mlx_pixel_put(img, start, colour);
			if (gradient_shallow(start, end))
				start.y--;
			else 
				start.x++;
			i++;
		}
		if (gradient_shallow(start, end))
			start.x++;
		else
			start.y--;
	}
}

void	draw_x_negative(t_img *img, t_coord start, t_coord end, int colour)
{
	int		gradient;
	int		i;
	
	gradient = abs((end.y - start.y) / (end.x - start.x));
	if (!gradient)
		gradient = abs((end.x - start.x) / (end.y - start.y));
	while (start.x > end.x && start.y < end.y)
	{
		i = 0;
		while (i < gradient)
		{
			my_mlx_pixel_put(img, start, colour);
			if (gradient_shallow(start, end))
				start.y++;
			else 
				start.x--;
			i++;
		}
		if (gradient_shallow(start, end))
			start.x--;
		else
			start.y++;
	}
}

void	draw_both_positive(t_img *img, t_coord start, t_coord end, int colour)
{
	int		gradient;
	int		i;
	
	gradient = (end.y - start.y) / (end.x - start.x);
	if (!gradient)
		gradient = (end.x - start.x) / (end.y - start.y);
	while (start.x < end.x && start.y < end.y)
	{
		i = 0;
		while (i < gradient)
		{
			my_mlx_pixel_put(img, start, colour);
			if (gradient_shallow(start, end))
				start.y++;
			else 
				start.x++;
			i++;
		}
		if (gradient_shallow(start, end))
			start.x++;
		else
			start.y++;
	}	
}

void	draw_line(t_img *img, t_coord start, t_coord end, int colour)
{
	if ((end.y - start.y) < 0 && (end.x - start.x) < 0)
		draw_both_negative(img, start, end, colour);
	else if ((end.y - start.y) < 0)
		draw_y_negative(img, start, end, colour);
	else if ((end.x - start.x) < 0)
		draw_x_negative(img, start, end, colour);
	else
		draw_both_positive(img, start, end, colour);
}

int	main(void)
{
	t_mlx_data	mlx;
	t_coord		start;
	t_coord		end;

	mlx.ptr = mlx_init();
	if (!mlx.ptr)
		return (1);
	mlx.win = mlx_new_window(mlx.ptr, WIN_LEN, WIN_HEIGHT, "FdF");
	if (!mlx.win)
	{
		mlx_destroy_display(mlx.ptr);
		free(mlx.ptr);
		return (1);
	}
	if (!initialize_img(&mlx))
		return (1);
//	colour_background(mlx.img, 0xFFFF0000); // not working !
	start.x = 100;
	start.y = 700;
	end.x = 900;
	end.y = 200;
	draw_line(&mlx.img, start, end, 0xFFFFFFFF);
	mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.img.ptr, 0, 0);
	mlx_key_hook(mlx.win, key_event, &mlx);
	mlx_loop(mlx.ptr);	
}
/* condition */