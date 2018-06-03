/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 11:02:25 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/20 13:32:26 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int		ft_square_is_char(int height, int width, int i, int j)
{
	if (i == 0 || i == height - 1)
		return (1);
	if (j == 0 || j == width - 1)
		return (1);
	return (0);
}

int		ft_check_square_chars(char *str, int height, int width)
{
	int i;
	int j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < height)
		{
			if (ft_square_is_char(height, width, i, j)
					!= !ft_is_space(*str))
				return (INVALID_CHAR);
			str++;
			j++;
		}
		if (*str != '\n' && *str != '\0')
			return (INVALID_STRUCTURE);
		str++;
		i++;
	}
	if (*str != '\0')
		return (INVALID_CHAR);
	return (MATCHING_STRUCTURE);
}

int		ft_check_square(char *str)
{
	int height;
	int width;

	height = ft_count_lines(str);
	if (height == 0)
		return (INVALID_STRUCTURE);
	width = ft_get_line_width(str);
	if (width != height)
		return (INVALID_STRUCTURE);
	return (ft_check_square_chars(str, height, width));
}
