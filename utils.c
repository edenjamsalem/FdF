#include "FdF.h"

int	init_img(t_mlx_data *mlx)
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

char *find_offset(int x, int y, t_img *img)
{
	return (img->addr + ((y * img->line_len) + (x * (img->bpp / 8))));
}

void	my_mlx_pixel_put(t_img *img, t_coord *coord, int colour)
{
	char	*dst;

	dst = find_offset(coord->x, coord->y, img);
	*((unsigned int *)dst) = colour;
}

void	free_file(char ***file_elements)
{
	int			i;
	int			j;
	
	i = 0;
	while (file_elements[i])
	{
		j = 0;
		while (file_elements[i][j])
			free(file_elements[i][j++]);
		free(file_elements[i]);
		i++;
	}
	free(file_elements);
}

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

void	print_file(char ***file_elements, t_grid_data *grid)
{
	int			i;
	int			j;
	
	i = -1;
	while (file_elements[i])
	{
		j = -1;
		while (file_elements[i][j])
			ft_printf("%s ", file_elements[i][j++]);
		ft_printf("\n");
		i++;
	}
	ft_printf("grid len = %d\n", grid->len);
	ft_printf("grid width = %d\n", grid->width);
}

int	init_grid_coords(t_grid_data *grid)
{
	int 	i;
	int 	j;
	t_coord	*coord;
	
	grid->coords = malloc(sizeof(t_coord **) * grid->width);
	if (!grid->coords)
		return (0);
	i = 0;
	while (i < grid->width)
	{
		grid->coords[i] = malloc(sizeof(t_coord *) * grid->len);
		if (!grid->coords[i])
			return (0);
		j = 0;
		while (j < grid->len)
		{
			coord = malloc(sizeof(coord));
			coord->x = grid->start.x + (grid->box_width * j);
			coord->y = grid->start.y + (grid->box_len * i);
			grid->coords[i][j++] = coord;
		}
		i++;
	}
	return (1);
}

void	init_grid_data(t_grid_data *grid, char ***file_elements)
{
	grid->width = ft_2darr_len((void *)(file_elements)); 
	grid->len = ft_2darr_len((void *)(file_elements[0]));
	grid->box_len = ((WIN_LEN / 2) / grid->len);
	grid->box_width = ((WIN_LEN / 2) / grid->len);
	grid->start.x = ((WIN_LEN / 2) - (0.5 * grid->len * grid->box_len));
	grid->start.y = ((WIN_HEIGHT / 2) - (0.5 * grid->width * grid->box_width));
	init_grid_coords(grid);
}