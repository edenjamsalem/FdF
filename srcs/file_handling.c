/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamsalem <eamsalem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:26:10 by eamsalem          #+#    #+#             */
/*   Updated: 2024/08/02 12:38:13 by eamsalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

static char	*ft_strjoin_free(char *file_contents, char *line, t_mlx_data *mlx)
{
	char	*new_str;
	int		tot_len;
	int		i;
	int		j;

	tot_len = ft_strlen(file_contents) + ft_strlen(line);
	new_str = malloc(sizeof(char) * (tot_len + 1));
	if (!new_str)
		malloc_error(mlx);
	i = 0;
	while (file_contents[i])
	{
		new_str[i] = file_contents[i];
		i++;
	}
	j = 0;
	while (line[j])
		new_str[i++] = line[j++];
	new_str[i] = '\0';
	free(file_contents);
	return (new_str);
}

char	*read_file(int fd, t_mlx_data *mlx)
{
	char	*line;
	char	*file_contents;

	file_contents = malloc(sizeof(char));
	if (!file_contents)
		malloc_error(mlx);
	file_contents[0] = '\0';
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			return (file_contents);
		file_contents = ft_strjoin_free(file_contents, line, mlx);
		free(line);
	}
}

char	***parse_file(char *file_contents, t_mlx_data *mlx)
{
	int		i;
	int		row_count;
	char	**rows;
	char	***file_data;

	rows = ft_split(file_contents, '\n');
	row_count = ft_2darr_len((void *)rows);
	file_data = malloc(sizeof(char **) * (row_count + 1));
	if (!file_data)
		malloc_error(mlx);
	i = 0;
	while (i < row_count)
	{
		file_data[i] = ft_split(rows[i], ' ');
		free(rows[i]);
		i++;
	}
	file_data[i] = NULL;
	free(file_contents);
	free(rows);
	return (file_data);
}
