#include "FdF.h"

//	TODO:
//	- correctly handle errors using exit() and perror()

//	- implement perspective projection equations to render image using z;
//		I need both the coords in 3D space AND its projected 2D coords
//		I will store the 3D coords, and then project to 2D when drawing the image

// 	- correctly calculate the centre point inc the z coord

//	- fix draw_grid fn to work for rotated images 


int	main(int argc, char **argv)
{
	t_mlx_data	mlx;
	int			fd;

	if (argc < 2)
		return (1);
	if (!(mlx.ptr = mlx_init()))
		return (1);
	if (!init_mlx_win(&mlx))
		return (1);
	if (!init_img(&mlx.img, &mlx))
		return (1);
	if (!(fd = open(argv[1], O_RDONLY)))
		return (1);
	mlx.file_elements = parse_file(fd);
	init_grid_data(&mlx.grid, mlx.file_elements);
//	draw_grid(&mlx.img, &mlx.grid, 0xFFFFFFFF);
	draw_grid_points(&mlx.img, &mlx.grid, 0xFFFFFFFF);
	mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.img.ptr, 0, 0);

//	mlx_hook(&mlx.win, DESTROY_EVT, STRUCT_NOTIFY_MSK, close_window, &mlx); // NOT WORKING
	mlx_hook(mlx.win, KEY_PRS_EVT, KEY_PRS_MSK, key_event, &mlx);
	mlx_loop(mlx.ptr);	
}
