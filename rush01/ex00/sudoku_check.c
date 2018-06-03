/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 14:48:57 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/13 19:09:46 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

extern struct s_udoku g_sudoku;

int		ft_check_column(int x, int i)
{
	int j;

	j = 0;
	while (j < 9)
	{
		if (g_sudoku.grid[x][j] == i)
			return (FALSE);
		j++;
	}
	return (TRUE);
}

int		ft_check_row(int y, int i)
{
	int j;

	j = 0;
	while (j < 9)
	{
		if (g_sudoku.grid[j][y] == i)
			return (FALSE);
		j++;
	}
	return (TRUE);
}

int		ft_check_section(int x, int y, int i)
{
	int j;
	int k;

	j = 0;
	while (j < 3)
	{
		k = 0;
		while (k < 3)
		{
			if (g_sudoku.grid[j + 3 * (x / 3)][k + ((y / 3) * 3)] == i)
				return (FALSE);
			k++;
		}
		j++;
	}
	return (TRUE);
}

/*
** x and y: position on grid
** i: value to try and place
*/

int		ft_try_placement(int x, int y, int i)
{
	return (ft_check_column(x, i)
			&& ft_check_row(y, i)
			&& ft_check_section(x, y, i));
}

int		ft_check_grid(void)
{
	int i;
	int j;
	int k;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			k = g_sudoku.grid[i][j];
			if (k != 0)
			{
				g_sudoku.grid[i][j] = 0;
				if (!ft_try_placement(i, j, k))
					return (INVALID_GRID);
				g_sudoku.grid[i][j] = k;
			}
			j++;
		}
		i++;
	}
	return (TRUE);
}
