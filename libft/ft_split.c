/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamsalem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:58:50 by eamsalem          #+#    #+#             */
/*   Updated: 2024/04/15 18:19:16 by eamsalem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	skip_c(char const *s, char c, int i)
{
	while (s[i] && s[i] == c)
		i++;
	return (i);
}

static int	skip_word(char const *s, char c, int i)
{
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	*get_word(char const *s, char c, int i)
{
	int		j;
	int		word_len;
	char	*word;

	word_len = (skip_word(s, c, i) - i);
	word = malloc(sizeof(char) * (word_len + 1));
	if (!word)
		return (NULL);
	j = 0;
	while (s[i] && s[i] != c)
		word[j++] = s[i++];
	word[j] = '\0';
	return (word);
}

static int	count_words(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	i = skip_c(s, c, i);
	while (s[i])
	{
		i = skip_word(s, c, i);
		count++;
		i = skip_c(s, c, i);
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		word_count;
	char	**split_strs;

	word_count = count_words(s, c);
	split_strs = malloc(sizeof(char *) * (word_count + 1));
	if (!split_strs)
		return (NULL);
	i = 0;
	j = 0;
	i = skip_c(s, c, i);
	while (j < word_count)
	{
		split_strs[j] = get_word(s, c, i);
		i = skip_word(s, c, i);
		i = skip_c(s, c, i);
		j++;
	}
	split_strs[j] = 0;
	return (split_strs);
}
/*
#include <stdio.h>

int	main(void)
{
	int	i;
	char	**strs = ft_split("  hello my name is eden ", ' ');

	i = 0;
	while (strs[i])
	{
		printf("%s\n", strs[i]);
		i++;
	}
}*/
