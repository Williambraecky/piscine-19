/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku_atos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouvroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 11:21:42 by nrouvroy          #+#    #+#             */
/*   Updated: 2018/05/13 19:36:26 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

extern struct s_udoku	g_sudoku;

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_str_equals(char *s1, char *s2)
{
	int i;

	i = 0;
	while (*(s1 + i) == *(s2 + i))
	{
		if (*(s1 + i) == '\0')
			return (TRUE);
		i++;
	}
	return (FALSE);
}

int		ft_parse_grid(int argc, char **argv)
{
	int i;
	int j;

	if (argc < 10)
		return (INVALID_ARGC);
	i = 1;
	while (i < 10)
	{
		j = -1;
		while (argv[i][++j])
		{
			if (argv[i][j] >= '1' && argv[i][j] <= '9')
				g_sudoku.grid[i - 1][j] = argv[i][j] - 48;
			else if (argv[i][j] == '.')
				g_sudoku.grid[i - 1][j] = 0;
			else
				return (INVALID_CHAR);
		}
		if (j != 9)
			return (INVALID_ARGLEN);
		i++;
	}
	if (argc > 10 && ft_str_equals(argv[10], "fancy"))
		g_sudoku.fancy = TRUE;
	return (ft_check_grid());
}

void	ft_print_grid(void)
{
	int		i;
	int		j;

	i = -1;
	while (++i < 9)
	{
		j = -1;
		while (++j < 9)
		{
			ft_putchar('0' + g_sudoku.grid[i][j]);
			if (g_sudoku.fancy && j != 0 && (j + 1) % 3 == 0 && j != 8)
				write(1, " |", 2);
			if (j != 8)
				write(1, " ", 1);
		}
		write(1, "\n", 1);
		if (g_sudoku.fancy && i != 0 && (i + 1) % 3 == 0 && i != 8)
		{
			j = 0;
			while (j++ < 21)
				write(1, "-", 1);
			write(1, "\n", 1);
		}
	}
	return ;
}
