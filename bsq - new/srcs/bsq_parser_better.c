/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_parser_better.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 07:16:05 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/23 11:50:58 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

extern t_bsq	*g_bsq_info;
extern t_board	*g_board;

t_bsq	*ft_create_bsq_info(void)
{
	t_bsq	*bsq_info;

	bsq_info = (t_bsq *)malloc(sizeof(t_bsq));
	if (bsq_info)
	{
		bsq_info->height = 0;
		bsq_info->width = 0;
		bsq_info->empty = 0;
		bsq_info->obstacle = 0;
		bsq_info->full = 0;
		bsq_info->solution = ft_empty_solution();
	}
	return (bsq_info);
}

int		ft_parse_info(char *buffer)
{
	int height;
	int j;
	int info_width;

	info_width = ft_first_line_len(buffer);
	if (info_width < 4 || info_width == 14)
		return (INVALID_INFO);
	buffer += (info_width);
	g_bsq_info->full = *(--buffer);
	g_bsq_info->obstacle = *(--buffer);
	g_bsq_info->empty = *(--buffer);
	if (g_bsq_info->full == g_bsq_info->obstacle || g_bsq_info->full ==
			g_bsq_info->empty || g_bsq_info->obstacle == g_bsq_info->empty)
		return (INVALID_MAP);
	buffer -= info_width - 3;
	height = 0;
	j = -1;
	while (*(buffer + ++j) && j < (info_width - 3))
	{
		if (*(buffer + j) < '0' || *(buffer + j) > '9')
			return (INVALID_INFO);
		height = height * 10 + (*(buffer + j) - '0');
	}
	g_bsq_info->height = height;
	return (PARSE_OK);
}

int		ft_parse_line(int fd, int line)
{
	int j;
	int o_count;

	g_board->data[line] = (char *)malloc(sizeof(char) * g_bsq_info->width + 1);
	g_board->solving[line] = (int *)malloc(sizeof(int) * g_bsq_info->width);
	if (g_board->data[line] == NULL || g_board->solving[line] == NULL)
		return (ft_free_on_fail(line) + NO_MEMORY);
	o_count = 0;
	j = read(fd, g_board->data[line], g_bsq_info->width + 1);
	if (j != g_bsq_info->width + 1)
		return (INVALID_MAP);
	j = 0;
	while (j < g_bsq_info->width)
	{
		if (!ft_check_char_validity(g_board->data[line][j]))
			return (INVALID_MAP);
		if (g_board->data[line][j] == g_bsq_info->empty)
		{
			if (line == 0 || j == 0)
				g_board->solving[line][j] = 1;
			else
				g_board->solving[line][j] = min(g_board->solving[line - 1][j - 1], g_board->solving[line - 1][j], g_board->solving[line][j - 1]) + 1;
			if (g_bsq_info->solution->size < g_board->solving[line][j])
			{
				g_bsq_info->solution->size = g_board->solving[line][j];
				g_bsq_info->solution->x = j;
				g_bsq_info->solution->y = line;
			}
		}
		else
			g_board->solving[line][j] = 0;
		j++;
	}
	if (g_board->data[line][j] != '\n')
		return (INVALID_MAP);
	return (PARSE_OK);
}

int		ft_parse_lines(int fd, char *buffer, char *file)
{
	int		result;
	int		width;
	int		j;

	width = ft_file_get_line_len(fd, buffer, 14);
	if (close(fd) == -1 || width == 0 || g_bsq_info->height == 0)
		return (width == 0 ? INVALID_MAP : INVALID_FILE);
	if ((fd = open(file, O_RDONLY)) == -1)
		return (INVALID_FILE);
	ft_file_skip_first_line(fd);
	g_bsq_info->width = width;
	j = 0;
	while (j < g_bsq_info->height)
	{
		if ((result = ft_parse_line(fd, j++)) != PARSE_OK)
			return (close(fd) == -1 ? INVALID_FILE : result);
	}
	return (close(fd) == -1 ? INVALID_FILE : PARSE_OK);
}

int		ft_parse_bsq(char *file)
{
	char	buffer[14 + 1];
	int		result;
	int		fd;
	int		j;

	if ((fd = open(file, O_RDONLY)) == -1)
		return (INVALID_FILE);
	j = read(fd, buffer, 14);
	buffer[j] = '\0';
	g_bsq_info = ft_create_bsq_info();
	if (g_bsq_info == NULL)
		return (NO_MEMORY);
	if ((result = ft_parse_info(buffer)) != PARSE_OK)
		return (result);
	if (close(fd) == -1)
		return (INVALID_FILE);
	if ((fd = open(file, O_RDONLY)) == -1)
		return (INVALID_FILE);
	ft_file_skip_first_line(fd);
	if ((result = ft_init_board()) != PARSE_OK)
		return (result);
	if ((result = ft_parse_lines(fd, buffer, file)) != PARSE_OK)
		return (result);
	return (PARSE_OK);
}
