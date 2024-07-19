#include "FdF.h"

char	***parse_file(int fd)
{
	int		i;
	char	*line;
	char 	***file_elements;

	i = 0;
	file_elements = malloc(sizeof(char *) * 100); // Make this dynamic !
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		line[ft_strlen(line) - 1] = '\0';
		file_elements[i] = ft_split(line, ' ');
		free(line);
		i++;
	}
	file_elements[i] = NULL;
	return (file_elements); 
}

void	initialize_grid(t_grid *grid, char ***file_elements)
{
	grid->width = ft_2darr_len((void *)(file_elements)); 
	grid->len = ft_2darr_len((void *)(file_elements[0]));
	grid->box_len = (WIN_LEN / 2) / (grid->len - 1);
	grid->box_width = (WIN_HEIGHT / 2) / (grid->width - 1);
	grid->start.x = (WIN_LEN / 2);
	grid->start.y = (WIN_HEIGHT / 2);
}

void	draw_grid(t_img *img, t_grid *grid/* char ***file_elements*/)
{
	int 	i;
	int 	j;
	t_coord	start;
	t_coord	next;
	//draw_horizontal_lines(img, grid, file_elements);
	//draw_vertical_lines(img, grid, file_elements);

	i = 0;
	start = grid->start;
	while (i < grid->width)
	{
		start.x += (grid->box_len * i);
		start.y += (grid->box_width * i);
		j = 0;
		while (j < grid->len)
		{
			next.x = start.x + (grid->box_len * j);
			next.y = start.y + (grid->box_width * j);
			draw_line(img, &start, &next, 0xFFFFFFFF);
			j++;
			ft_printf("1\n");
		}
		i++;
	}
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
	if (!initialize_img(&mlx))
		return (1);
	fd = open(argv[1], O_RDONLY);
	mlx.file_elements = parse_file(fd);
//	print_file(mlx.file_elements, &mlx.grid);
	initialize_grid(&mlx.grid, mlx.file_elements);
	my_mlx_pixel_put(&mlx.img, &mlx.grid.start, 0xFFFFFFFF);
	ft_printf("box len %d\n", mlx.grid.box_len);
	ft_printf("box width %d\n", mlx.grid.box_width);
	ft_printf("grid len %d\n", mlx.grid.len);
	ft_printf("grid width %d\n", mlx.grid.width);
	printf("start.x %f\n", mlx.grid.start.x);
	printf("start.y %f\n", mlx.grid.start.y);
	my_mlx_pixel_put(&mlx.img, &mlx.grid.start, 0xFFFFFFFF);
//	draw_grid(&mlx.img, &mlx.grid);
	//	DRAW FLAT GRID FROM START COORD
	//	CALC GRID DEPENDING ON INPUT VALUES

	mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.img.ptr, 0, 0);
//	mlx_hook(&mlx.win, DESTROY_EVT, STRUCT_NOTIFY_MSK, close_window, &mlx); // NOT WORKING
	mlx_key_hook(mlx.win, key_event, &mlx);
	mlx_loop(mlx.ptr);	
}
