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
	grid->box_len = 50;
	grid->box_width = 50;
	grid->start.x = (WIN_LEN / 2) - (0.5 * grid->len * grid->box_len);
	grid->start.y = (WIN_HEIGHT / 2) - (0.5 * grid->width * grid->box_width);
}

void	draw_horizontal_lines(t_img *img, t_grid *grid)
{
	int 	i;
	int 	j;
	t_coord	start;
	t_coord	next;
	
	i = 0;
	while (i < grid->width)
	{
		start.y = grid->start.y + (grid->box_width * i);
		next.y = start.y;
		j = 0;
		while (j < grid->len - 1)
		{
			start.x = grid->start.x + (grid->box_width * j);
			next.x = start.x + grid->box_len;
			draw_line(img, &start, &next, 0xFFFFFFFF);
			j++;
		}
		i++;
	}
}

void	draw_vertical_lines(t_img *img, t_grid *grid)
{
	int 	i;
	int 	j;
	t_coord	start;
	t_coord	next;
	
	i = 0;
	while (i < grid->len)
	{
		start.x = grid->start.x + (grid->box_len * i);
		next.x = start.x;
		j = 0;
		while (j < grid->width - 1)
		{
			start.y = grid->start.y + (grid->box_len * j);
			next.y = start.y + grid->box_width;
			draw_line(img, &start, &next, 0xFFFFFFFF);
			j++;
		}
		i++;
	}

}

void	draw_grid(t_img *img, t_grid *grid/* char ***file_elements*/)
{
	draw_horizontal_lines(img, grid);
	draw_vertical_lines(img, grid);
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
	
	ft_printf("box len %d\n", mlx.grid.box_len);
	ft_printf("box width %d\n", mlx.grid.box_width);
	ft_printf("grid len %d\n", mlx.grid.len);
	ft_printf("grid width %d\n", mlx.grid.width);
	printf("start.x %f\n", mlx.grid.start.x);
	printf("start.y %f\n", mlx.grid.start.y);
	
	draw_grid(&mlx.img, &mlx.grid);
	mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.img.ptr, 0, 0);
//	mlx_hook(&mlx.win, DESTROY_EVT, STRUCT_NOTIFY_MSK, close_window, &mlx); // NOT WORKING
	mlx_key_hook(mlx.win, key_event, &mlx);
	mlx_loop(mlx.ptr);	
}
