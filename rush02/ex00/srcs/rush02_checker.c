/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 14:34:46 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/20 11:55:14 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

t_rush_config	g_rush_config;

char			ft_get_char(int x, int y, int i, int j)
{
	if (i == 0 && j == 0)
		return (g_rush_config.top_left);
	else if (i == x - 1 && j == 0)
		return (g_rush_config.top_right);
	else if (i == 0 && j == y - 1)
		return (g_rush_config.bottom_left);
	else if (i == x - 1 && j == y - 1)
		return (g_rush_config.bottom_right);
	else if (i == 0 || i == x - 1)
		return (g_rush_config.walls);
	else if (j == 0 || j == y - 1)
		return (g_rush_config.top_bottom);
	return (' ');
}

int				ft_check(char *input, int height, int width)
{
	int i;
	int j;

	j = 0;
	while (j < height)
	{
		i = 0;
		while (i < width)
		{
			if (*input != ft_get_char(width, height, i, j))
				return (INVALID_CHAR);
			i++;
			input++;
		}
		if (*input != '\n' && *input != '\0')
			return (INVALID_STRUCTURE);
		if (*input)
			input++;
		j++;
	}
	if (*input)
		return (INVALID_STRUCTURE);
	return (MATCHING_STRUCTURE);
}

int				ft_check_rush(t_rush_config config, char *input)
{
	int width;
	int height;

	height = ft_count_lines(input);
	width = ft_get_line_width(input);
	if (height == 0 || width == 0)
		return (INVALID_STRUCTURE);
	g_rush_config = config;
	return (ft_check(input, height, width));
}
