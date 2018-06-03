/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 14:01:26 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/23 11:21:08 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_bsq	*g_bsq_info;
t_board	*g_board;

void	arg_cycle(char *file)
{
	int result;

	g_bsq_info = NULL;
	g_board = NULL;
	result = ft_parse_bsq(file);
	if (result == PARSE_OK)
	{
		ft_bsq_resolve();
		ft_print_bsq();
	}
	else
		write(2, "map error\n", 10);
	if (g_bsq_info != NULL)
		free(g_bsq_info);
	if (g_board != NULL)
		free(g_board);
}

int		main(int argc, char *argv[])
{
	int i;

	if (argc == 1)
	{
		ft_bsq_stdinput();
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		arg_cycle(argv[i]);
		if (i != argc - 1)
			write(1, "\n", 1);
		i++;
	}
	return (0);
}
