#include "../FdF.h"

//	TODO:
// 	- add colour gradient

//	- if there is time: add a scaling factor depending on range of z values

int	main(int argc, char **argv)
{
	t_mlx_data	mlx;
	int			fd;
	char 		*file_contents;

	if (argc != 2)
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit(EXIT_FAILURE);
	init_mlx_data(&mlx);
	init_img_data(&mlx.img, &mlx);
	file_contents = read_file(fd);
	mlx.file_elements = parse_file(file_contents);
	init_grid_data(&mlx.grid, mlx.file_elements);
	isometric_projection(&mlx.grid);
	draw_model(&mlx);
	mlx_hook(mlx.win, KEY_PRS_EVT, KEY_PRS_MSK, key_event, &mlx);
	mlx_hook(mlx.win, BTN_PRS_EVT, BTN_PRS_MSK, mouse_event, &mlx);
	mlx_hook(mlx.win, DESTROY_EVT, STRUCT_NOTIFY_MSK, close_window, &mlx);
	mlx_loop(mlx.ptr);	
}
