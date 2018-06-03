/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku_resolver.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 16:56:01 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/13 19:42:42 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

extern struct s_udoku	g_sudoku;

void	ft_place(int x, int y, int i)
{
	g_sudoku.grid[x][y] = i;
}

void	ft_reset(int x, int y)
{
	g_sudoku.grid[x][y] = 0;
}

int		ft_is_sudoku_valid(void)
{
	int i;
	int j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			if (g_sudoku.grid[i][j] == 0)
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}
