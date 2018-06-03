/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02_rectangle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 12:01:27 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/20 13:36:05 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int		ft_check_rectangle_chars(char *str, int height, int width)
{
	int i;
	int j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
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

int		ft_check_rectangle(char *str)
{
	int height;
	int width;

	height = ft_count_lines(str);
	width = ft_get_line_width(str);
	if (height == 0 || width == 0)
		return (INVALID_STRUCTURE);
	return (ft_check_rectangle_chars(str, height, width));
}
