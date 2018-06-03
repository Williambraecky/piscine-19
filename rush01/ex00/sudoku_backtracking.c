/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku_backtracking.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 17:30:44 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/13 20:17:26 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"
#include <stdio.h>

extern struct s_udoku	g_sudoku;

int		ft_order_placer(t_pos tab[81], int order, int max)
{
	int x;
	int y;
	int i;
	int j;
	int result;

	if (order == max)
		return (1);
	x = tab[order].x;
	y = tab[order].y;
	i = 0;
	j = 0;
	result = 0;
	while (++i < 10)
	{
		if (ft_try_placement(x, y, i))
		{
			ft_place(x, y, i);
			j++;
			result += ft_order_placer(tab, order + 1, max);
			if (!result)
				ft_reset(x, y);
		}
	}
	return (j ? result : 0);
}

void	ft_t_pos_insert(t_pos *pos, int x, int y)
{
	pos->x = x;
	pos->y = y;
}

void	ft_order_increment(void)
{
	t_pos	tab[81];
	int		i;
	int		x;
	int		y;
	int		l;

	i = -1;
	l = 0;
	while (++i < 9)
	{
		x = -1;
		while (++x < 9)
		{
			y = -1;
			while (++y < 9)
			{
				if (g_sudoku.grid[x][y] == 0 && g_sudoku.ordergrid[x][y] == i)
				{
					ft_t_pos_insert(&tab[l], x, y);
					l++;
				}
			}
		}
	}
	ft_order_placer(tab, 0, l);
}

void	ft_fill_order_grid(void)
{
	int x;
	int y;
	int k;

	x = 0;
	while (x < 9)
	{
		y = 0;
		while (y < 9)
		{
			k = 1;
			while (k < 10)
			{
				if (g_sudoku.grid[x][y] != 0)
					break ;
				g_sudoku.ordergrid[x][y] += ft_try_placement(x, y, k);
				k++;
			}
			y++;
		}
		x++;
	}
	ft_order_increment();
}
