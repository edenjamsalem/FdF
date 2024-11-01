/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamsalem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:30:44 by eamsalem          #+#    #+#             */
/*   Updated: 2024/05/03 17:53:22 by eamsalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstnew_buf(void)
{
	t_list	*list;
	int		i;

	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->content = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!list->content)
	{
		ft_lstclear(&list);
		return (NULL);
	}
	i = 0;
	while (i < BUFFER_SIZE + 1)
		((char *)(list->content))[i++] = '\0';
	list->next = NULL;
	return (list);
}

int	get_line_len(t_list *line_buff)
{
	int		len;
	int		i;
	char	*node_content;

	if (!line_buff || !line_buff->content)
		return (0);
	len = 0;
	while (line_buff)
	{
		i = 0;
		node_content = (char *)(line_buff->content);
		while (node_content[i] && node_content[i] != '\n')
		{
			len++;
			i++;
		}
		if (node_content[i] == '\n')
			return (++len);
		line_buff = line_buff->next;
	}
	return (len);
}

int	check_node_for_nl(t_list *line_buff)
{
	char	*node_content;
	int		i;

	if (!line_buff || !line_buff->content)
		return (0);
	node_content = (char *)(line_buff->content);
	if (!node_content)
		return (0);
	i = 0;
	while (node_content[i])
	{
		if (node_content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	ft_lstclear_butlast(t_list **lst)
{
	t_list	*tmp;

	if (!lst || !*lst)
		return ;
	while ((*lst)->next)
	{
		tmp = (*lst)->next;
		free((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
}
