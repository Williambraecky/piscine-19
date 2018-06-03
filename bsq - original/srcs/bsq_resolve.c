/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_resolve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 10:13:38 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/23 17:59:25 by nrouvroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

extern t_board	*g_board;
extern t_bsq	*g_bsq_info;

void		ft_create_new_list(t_list **list)
{
	t_list *start;

	start = NULL;
	list = &start;
}

void		ft_test_solutions(int **table, int i, int j,
		t_solution *current_solution)
{
	int size;

	size = (current_solution->size + 1);
	while ((i + size) < g_bsq_info->height &&
			(j + size) < g_bsq_info->width)
	{
		if (!(ft_test_square(table, i, j, size)))
		{
			if ((j + size) == g_bsq_info->width - 1)
			{
				i++;
				j = -1;
			}
			j++;
			continue ;
		}
		current_solution->x = j;
		current_solution->y = i;
		current_solution->size = size;
		size++;
	}
}

t_solution	*ft_find_biggest_square(int **table)
{
	t_solution	*solution;
	int			i;
	int			j;

	solution = ft_empty_solution();
	i = 0;
	j = 0;
	ft_test_solutions(table, i, j, solution);
	return (solution);
}

void		ft_bsq_resolve(void)
{
	t_solution	*solution;
	int			**table;
	int			i;

	table = g_board->solving;
	solution = ft_find_biggest_square(table);
	if (solution->size != -1)
		ft_replace_board_with_solution(solution);
	i = 0;
	free(solution);
}
