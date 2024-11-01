/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamsalem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 10:33:27 by eamsalem          #+#    #+#             */
/*   Updated: 2024/05/03 17:52:52 by eamsalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_line_from_buf(t_list *line_buff, char *line)
{
	int		i;
	char	*node_content;

	if (!line_buff)
		return (NULL);
	while (line_buff)
	{
		node_content = (char *)(line_buff->content);
		i = 0;
		while (node_content[i])
		{
			*line = node_content[i];
			if (node_content[i] == '\n')
			{
				*(++line) = '\0';
				return (&node_content[++i]);
			}
			i++;
			line++;
		}
		line_buff = line_buff->next;
	}
	*(line) = '\0';
	return (NULL);
}

static int	read_file_til_nl(int fd, t_list **line_buff)
{
	int		bytes_read;
	t_list	*new_node;

	while (1)
	{
		new_node = ft_lstnew_buf();
		if (!new_node)
			return (0);
		bytes_read = read(fd, new_node->content, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			ft_lstclear(&new_node);
			if (bytes_read == -1)
				return (0);
			return (1);
		}
		((char *)(new_node->content))[bytes_read] = '\0';
		ft_lstadd_back(line_buff, new_node);
		if (check_node_for_nl(new_node))
			return (1);
	}
}

static int	rem_prev_line_from_node(t_list **line_buff, char *next_chr)
{
	t_list	*new_node;
	int		i;

	new_node = ft_lstnew_buf();
	if (!new_node)
	{
		ft_lstclear(line_buff);
		return (0);
	}
	i = 0;
	while (*next_chr)
	{
		((char *)(new_node->content))[i++] = *next_chr;
		next_chr++;
	}
	((char *)((*line_buff)->content))[i] = '\0';
	ft_lstclear(line_buff);
	*line_buff = new_node;
	return (1);
}

static char	*get_line(t_list **line_buff)
{
	char	*line;
	char	*next_chr;

	if (!line_buff || !*line_buff)
		return (NULL);
	line = malloc(sizeof(char) * (get_line_len(*line_buff) + 1));
	if (!line)
	{
		ft_lstclear(line_buff);
		return (NULL);
	}
	next_chr = read_line_from_buf(*line_buff, line);
	if (!next_chr || !*next_chr)
	{
		ft_lstclear(line_buff);
		*line_buff = NULL;
	}
	else
	{
		ft_lstclear_butlast(line_buff);
		if (!rem_prev_line_from_node(line_buff, next_chr))
			return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static t_list	*line_buff[100];

	if (fd < 0 || fd >= 100 || BUFFER_SIZE <= 0)
		return (NULL);
	if (line_buff[fd])
	{
		if (!check_node_for_nl(line_buff[fd]))
		{
			if (!read_file_til_nl(fd, &line_buff[fd]))
			{
				ft_lstclear(line_buff);
				return (NULL);
			}
		}
	}
	else
	{
		if (!read_file_til_nl(fd, &line_buff[fd]))
		{
			ft_lstclear(line_buff);
			return (NULL);
		}
	}
	return (get_line(&line_buff[fd]));
}

/*
int	main(void)
{
	int	fd1;
	int	fd2;
	int	fd3;
	int	fd4;
	int	i;
//	int	no_lines = 10;
	char	*line;
	
	fd1 = open("./files/41_no_nl", O_RDONLY);
	fd2 = open("./files/41_with_nl", O_RDONLY);
	fd3 = open("./files/42_no_nl", O_RDONLY);
	fd4 = open("./files/42_with_nl", O_RDONLY);
	i = 0;
	while (i < 1)
	{
		line = get_next_line(fd1);
		printf("%s", line);
		i++;
		free(line);
	}
	i = 0;
	while (i < 2)
	{
		line = get_next_line(fd2);
		printf("%s", line);
		i++;
		free(line);
	}
	i = 0;
	while (i < 1)
	{
		line = get_next_line(fd3);
		printf("%s", line);
		i++;
		free(line);
	}
	i = 0;
	while (i < 2)
	{
		line = get_next_line(fd4);
		printf("%s", line);
		i++;
		free(line);
	}
	
}*/
