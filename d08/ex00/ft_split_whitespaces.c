/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 11:35:13 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/10 10:52:42 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_is_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

int		ft_get_word_index(char *str, int position)
{
	int i;
	int j;

	i = 0;
	j = -1;
	while (*(str + i))
	{
		while (*(str + i) && ft_is_space(*(str + i)))
			i++;
		j += *(str + i) && !ft_is_space(*(str + i));
		if (j == position)
			return (i);
		while (*(str + i) && !ft_is_space(*(str + i)))
			i++;
		i++;
	}
	return (0);
}

char	*ft_get_word(char *str, int position)
{
	char	*word;
	int		i;
	int		j;
	int		k;

	i = ft_get_word_index(str, position);
	j = i;
	while (*(str + j) && !ft_is_space(*(str + j)))
		j++;
	word = (char *)malloc(sizeof(char) * (j - i));
	k = 0;
	while (i < j)
	{
		word[k++] = *(str + i);
		i++;
	}
	word[k] = '\0';
	return (word);
}

int		ft_count_words(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (*(str + i))
	{
		while (*(str + i) && ft_is_space(*(str + i)))
			i++;
		j += *(str + i) && !ft_is_space(*(str + i));
		while (*(str + i) && !ft_is_space(*(str + i)))
			i++;
		i++;
	}
	return (j);
}

char	**ft_split_whitespaces(char *str)
{
	char	**result;
	char	*end;
	int		words;
	int		i;

	words = ft_count_words(str);
	result = (char **)malloc(sizeof(char *) * (words + 1));
	i = 0;
	while (i < words)
	{
		result[i] = ft_get_word(str, i);
		i++;
	}
	end = 0;
	result[i] = end;
	return (result);
}
