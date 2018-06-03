/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 13:14:36 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/10 16:30:06 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_str_startswith(char *str, char *charset)
{
	int i;

	i = 0;
	while (*(str + i) == *(charset + i))
	{
		if (*(charset + i + 1) == '\0')
			return (1);
		i++;
	}
	return (0);
}

int		ft_count_splits(char *str, char *charset, int charsetlen)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (*(str + i))
	{
		while (ft_str_startswith(str + i, charset))
			i += charsetlen;
		k += *(str + i) != '\0';
		while (*(str + i) && !ft_str_startswith(str + i, charset))
			i++;
	}
	return (k);
}

int		ft_get_str_index(char *str, char *split, int spllen, int position)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (*(str + i))
	{
		while (*(str + i) && ft_str_startswith(str + i, split))
			i += spllen;
		k += *(str + i) != '\0';
		if (position == k - 1)
			return (i);
		while (*(str + i) && !ft_str_startswith(str + i, split))
			i++;
	}
	return (i);
}

char	*ft_get_str_at_split(char *str, char *split, int spllen, int position)
{
	char	*result;
	int		i;
	int		j;
	int		k;

	i = ft_get_str_index(str, split, spllen, position);
	j = i;
	while (*(str + j))
	{
		if (ft_str_startswith(str + j, split))
			break ;
		j++;
	}
	result = (char *)malloc(sizeof(char) * j - i);
	k = 0;
	while (i < j)
	{
		result[k++] = *(str + i);
		i++;
	}
	result[k] = '\0';
	return (result);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		charsetlen;
	int		splits;
	int		i;

	charsetlen = 0;
	while (*(charset + charsetlen))
		charsetlen++;
	splits = ft_count_splits(str, charset, charsetlen);
	result = (char **)malloc(sizeof(char *) * (splits + 1));
	i = 0;
	while (i < splits)
	{
		result[i] = ft_get_str_at_split(str, charset, charsetlen, i);
		i++;
	}
	result[i] = 0;
	return (result);
}
