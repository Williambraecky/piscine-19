/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 11:02:53 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/23 18:09:54 by nrouvroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdio.h>

extern t_board	*g_board;
extern t_bsq	*g_bsq_info;

int				ft_init_board(void)
{
	g_board = (t_board *)malloc(sizeof(t_board));
	if (g_board == NULL)
		return (NO_MEMORY);
	g_board->data = (char **)malloc(sizeof(char *) * g_bsq_info->height);
	if (g_board->data == NULL)
		return (NO_MEMORY);
	g_board->solving = (int **)malloc(sizeof(int *) * g_bsq_info->height);
	if (g_board->data == NULL)
		return (NO_MEMORY);
	return (PARSE_OK);
}

void			ft_replace_board_with_solution(t_solution *solution)
{
	int i;
	int j;

	i = 0;
	while (i < solution->size)
	{
		j = 0;
		while (j < solution->size)
		{
			g_board->data[solution->y - i][solution->x - j] =
				g_bsq_info->full;
			j++;
		}
		i++;
	}
}

int				ft_file_get_line_len(int fd, char *buffer, int max)
{
	int break_;
	int i;
	int j;
	int k;

	i = 0;
	break_ = 0;
	while ((j = read(fd, buffer, max)) > 0)
	{
		k = 0;
		while (k < j)
		{
			if (buffer[k] == '\n')
			{
				break_ = 1;
				break ;
			}
			i++;
			k++;
		}
		if (break_)
			break ;
	}
	return (i);
}

t_solution		*ft_empty_solution(void)
{
	t_solution *solution;

	solution = (t_solution *)malloc(sizeof(t_solution));
	if (solution != NULL)
	{
		solution->x = -1;
		solution->y = -1;
		solution->size = -1;
	}
	return (solution);
}

int				ft_test_square(int **table, int i, int j, int size)
{
	int top_left;
	int top_right;
	int bottom_left;
	int bottom_right;
	int result;

	if (i == 0 || j == 0)
		top_left = 0;
	else
		top_left = table[i - 1][j - 1];
	if (j == 0)
		top_right = 0;
	else
		top_right = table[i + size][j - 1];
	if (i == 0)
		bottom_left = 0;
	else
		bottom_left = table[i - 1][j + size];
	bottom_right = table[i + size][j + size];
	result = bottom_right - bottom_left - top_right + top_left;
	if (result != 0)
		return (0);
	return (1);
}
