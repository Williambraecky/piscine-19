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

int min(int a, int b, int c)
{
    if (a < b) {
        return (a < c) ? a : c;
    } else {
        return (b < c) ? b : c;
    }
}


void		ft_test_solutions(int **table, int i, int j,
		t_solution *current_solution)
{
	int max = 1;
	
	for (int i = 1; i < g_bsq_info->height; i++) {
		for (int j = 1; j < g_bsq_info->width; j++) {
			if (g_board->solving[i][j] > max) {
				max = g_board->solving[i][j];
				current_solution->x = j;
				current_solution->y = i;
				current_solution->size = max;
			}
		}
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
	solution = g_bsq_info->solution;
	if (solution->size != -1)
		ft_replace_board_with_solution(solution);
	i = 0;
	free(solution);
}
