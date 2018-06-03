/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02_ftstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 13:13:50 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/20 11:51:35 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

void	ft_strcat(char *str, char *to_add, int str_start)
{
	int add_len;
	int j;
	int i;

	i = str_start;
	j = 0;
	add_len = ft_strlen(to_add);
	while (j < add_len)
	{
		str[i] = *(to_add + j);
		j++;
		i++;
	}
}

char	*ft_strdup(char *str)
{
	char	*dup;
	int		i;

	i = 0;
	dup = (char *)malloc(sizeof(char) * ft_strlen(str));
	while (dup != NULL && *str)
	{
		dup[i] = *str;
		str++;
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int		ft_get_line_width(char *str)
{
	int i;

	if (*str == '\0')
		return (0);
	i = 0;
	while (*str && *str != '\n')
	{
		i++;
		str++;
	}
	return (i);
}

int		ft_count_lines(char *str)
{
	int i;

	if (*str == '\0')
		return (0);
	i = 0;
	while (*str)
	{
		if (*str == '\n')
			i++;
		str++;
	}
	return (i);
}
