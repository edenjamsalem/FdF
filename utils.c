#include "FdF.h"

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

void	free_coords(t_grid_data *grid)
{
	int 	i;
	int 	j;
	
	i = 0;
	while (i < grid->width)
	{
		j = 0;
		while (j < grid->len)
			free(grid->coords[i][j++]);
		free(grid->coords[i]);
		i++;
	}
	free(grid->coords);
}

char	***parse_file(int fd)
{
	int		i;
	char	*line;
	char 	***file_elements;

	i = 0;
	file_elements = malloc(sizeof(char *) * 101); // Make this dynamic !
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

double	rad(int	degrees)
{
	return (degrees * (PI / 180));
}

void	recentre(t_grid_data *grid)
{
	int		i;
	int		j;
	double	sum_z;
	double	x_first;
	double	y_first;
	double	x_end;
	double	y_end;

	x_first = grid->coords[0][0]->x;
	y_first = grid->coords[0][0]->y;
	x_end = grid->coords[grid->width - 1][grid->len - 1]->x;
	y_end = grid->coords[grid->width - 1][grid->len - 1]->y;
	grid->centre.x = (x_first + x_end) / 2;
	grid->centre.y = (y_first + y_end) / 2;
	sum_z = 0;
	i = 0;
	while (i < grid->width)
	{
		j = 0;
		while (j < grid->len)
			sum_z += grid->coords[i][j++]->z;
		i++;
	}
	grid->centre.z = sum_z / (grid->width * grid->len);
}
