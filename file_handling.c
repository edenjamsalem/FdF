#include "FdF.h"

static char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*new_str;
	int		tot_len;
	int		i;
	int		j;

	tot_len = ft_strlen(s1) + ft_strlen(s2);
	new_str = malloc(sizeof(char) * (tot_len + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		new_str[i++] = s2[j++];
	new_str[i] = '\0';
	free(s1);
	free(s2);
	return (new_str);
}

char	*read_file(int fd)
{
	char	*line;
	char 	*file_contents;

	file_contents = malloc(sizeof(char));
	file_contents[0] = '\0';
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			return (file_contents); 
		file_contents = ft_strjoin_free(file_contents, line);
	}
}

char	***parse_file(char *file_contents)
{
	int		i;
	int		row_count;
	int		row_len;
	char	**rows;
	char	***file_elements;

	rows = ft_split(file_contents, '\n');
	row_count = ft_2darr_len((void *)rows);
	file_elements = malloc(sizeof(char **) * (row_count + 1));
	if (!file_elements)
		return (NULL);
	i = 0;
	while (i < row_count)
	{
		file_elements[i] = ft_split(rows[i], ' ');
		free(rows[i++]);
	}
	file_elements[i] = NULL;
	free(file_contents);
	free(rows);
	row_len = ft_2darr_len((void *)file_elements[0]);
	return (file_elements);
}