#include "FdF.h"

int	rad(int	degrees)
{
	return (degrees * (PI / 180));
}

int	main(int argc, char **argv)
{
	t_mlx_data	mlx;
	int			fd;

	if (argc < 2)
		return (1);
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
	if (!init_img(&mlx.img, &mlx))
		return (1);
	fd = open(argv[1], O_RDONLY);
	mlx.file_elements = parse_file(fd);
//	print_file(mlx.file_elements, &mlx.grid);
	init_grid_data(&mlx.grid, mlx.file_elements);
	
	ft_printf("grid len %d\n", mlx.grid.len);
	ft_printf("grid width %d\n", mlx.grid.width);
	ft_printf("box len %d\n", mlx.grid.box_len);
	ft_printf("box width %d\n", mlx.grid.box_width);
	printf("start.x %f\n", mlx.grid.start.x);
	printf("start.y %f\n", mlx.grid.start.y);
	
	draw_grid(&mlx.img, &mlx.grid, 0xFFFFFFFF);
	mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.img.ptr, 0, 0);

//	mlx_hook(&mlx.win, DESTROY_EVT, STRUCT_NOTIFY_MSK, close_window, &mlx); // NOT WORKING
	mlx_hook(mlx.win, KEY_PRS_EVT, KEY_PRS_MSK, key_event, &mlx);
	mlx_loop(mlx.ptr);	
}
