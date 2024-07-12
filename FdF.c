#include "FdF.h"
/*
void run_graphic(t_mlx_data mlx, t_img img)
{
	int		x;
	int		y;
	int		colour;
	
	colour = 0xFF00FF00; 
	y = 0;
	while (y < WIN_HEIGHT)
	{	
		x = 0;
		while (x < WIN_LEN)
			my_mlx_pixel_put(&img, colour);
		y++;
	}
	mlx_put_image_to_window(mlx.ptr, mlx.win, img.ptr, 0, 0);
}
*/
char *find_offset(int x, int y, t_img *img)
{
	return (img->addr + ((y * img->line_len) + (x * (img->bpp / 8))));
}

void	my_mlx_pixel_put(t_img *img, t_coord coord, int colour)
{
	char	*dst;

	dst = find_offset(coord.x, coord.y, img);
	*((unsigned int *)dst) = colour;
}


void	draw_line(t_mlx_data *mlx, t_coord start, t_coord end)
{
	int		gradient;
	int		colour;
	int		i;
	t_coord	line;

	gradient = (end.y - start.y) / (end.x - start.x);
	colour = 0xFFFFFFFF;
	line.x = start.x;
	line.y = start.y;
	while (line.x < end.x && line.y < end.y)
	{
		i = 0;
		while (i < gradient)
		{
			my_mlx_pixel_put(&mlx->img, line, colour);
			line.y++;
			i++;
		}
		line.x++;
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.ptr, 0, 0);
}
/*
void	generate_grid(t_mlx_data mlx)
{

}
*/

int	key_event(int keysym, t_mlx_data *mlx)
{
	if (keysym == ESC_KEY)
	{
		mlx_destroy_image(mlx->ptr, mlx->img.ptr);
		mlx_destroy_window(mlx->ptr, mlx->win);
		mlx_destroy_display(mlx->ptr);
		free(mlx->ptr);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	initialize_img(t_mlx_data *mlx)
{
	mlx->img.ptr = mlx_new_image(mlx->ptr, WIN_LEN, WIN_HEIGHT);
	if (!mlx->img.ptr)
	{
		mlx_destroy_window(mlx->ptr, mlx->win);
		mlx_destroy_display(mlx->ptr);
		free(mlx->ptr);
		return (0);
	}
	mlx->img.addr = mlx_get_data_addr(mlx->img.ptr, &mlx->img.bpp, \
							&mlx->img.line_len, &mlx->img.endian);
	if (!mlx->img.addr)
	{
		free(mlx->img.ptr);
		mlx_destroy_window(mlx->ptr, mlx->win);
		mlx_destroy_display(mlx->ptr);
		free(mlx->ptr);
		return (0);
	}
	return (1);
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
//	run_graphic(mlx, mlx.img);
	start.x = 150;
	start.y = 100;
	end.x = 300;
	end.y = 300;
	draw_line(&mlx, start, end);
//	generate_grid(mlx);
	mlx_key_hook(mlx.win, key_event, &mlx);
	mlx_loop(mlx.ptr);	
}
/* condition */