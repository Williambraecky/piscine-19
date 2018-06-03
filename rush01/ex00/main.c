/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouvroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 10:36:53 by nrouvroy          #+#    #+#             */
/*   Updated: 2018/05/13 19:46:04 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

struct s_udoku g_sudoku;

int	main(int argc, char **argv)
{
	int error;

	error = ft_parse_grid(argc, argv);
	if (error < 0)
	{
		write(1, "Error\n", 6);
		return (error);
	}
	ft_fill_order_grid();
	if (!ft_is_sudoku_valid())
	{
		write(1, "Error\n", 6);
		return (INVALID_SUDOKU);
	}
	ft_print_grid();
	return (0);
}
