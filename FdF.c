#include "FdF.h"

void colour_background(t_img img, int colour)
{
	t_coord coord;

	coord.y = 0;
	while (coord.y < WIN_HEIGHT)
	{	
		coord.x = 0;
		while (coord.x < WIN_LEN)
			my_mlx_pixel_put(&img, &coord, colour);
		coord.y++;
	}
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
	start.x = 0;
	start.y = 150;
	end.x = WIN_LEN - 1;
	end.y = 0;
	draw_line(&mlx.img, &start, &end, 0xFFFFFFFF);
	mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.img.ptr, 0, 0);
	mlx_key_hook(mlx.win, key_event, &mlx);
	mlx_loop(mlx.ptr);	
}
/* condition */