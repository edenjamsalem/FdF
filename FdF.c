#include "FdF.h"

//	TODO:
//	- correctly handle errors using exit() and perror()

// 	- add colour gradient

//	- create fn to clear window properly

// 	- add mouse hook to zoom and close window by clicking cross


int	main(int argc, char **argv)
{
	t_mlx_data	mlx;
	int			fd;
	char 		*file_contents;

	if (argc != 2)
		return (1);
	if (!(mlx.ptr = mlx_init()))
		return (1);
	if (!init_mlx_win(&mlx))
		return (1);
	if (!init_img(&mlx.img, &mlx))
		return (1);
	if (!(fd = open(argv[1], O_RDONLY)))
		return (1);
	file_contents = read_file(fd);
	mlx.file_elements = parse_file(file_contents);
	init_grid_data(&mlx.grid, mlx.file_elements);
	isometric_projection(&mlx.grid);
	draw_model(&mlx.img, &mlx.grid, 0xFFFFFFFF);
	mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.img.ptr, 0, 0);
	//mlx_hook(&mlx.win, DESTROY_EVT, STRUCT_NOTIFY_MSK, close_window, &mlx); // NOT WORKING
	mlx_hook(mlx.win, KEY_PRS_EVT, KEY_PRS_MSK, key_event, &mlx);
	mlx_loop(mlx.ptr);	
}
