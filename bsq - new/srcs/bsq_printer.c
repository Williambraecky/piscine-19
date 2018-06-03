/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 16:34:24 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/23 17:45:07 by nrouvroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

extern t_bsq	*g_bsq_info;
extern t_board	*g_board;

void	ft_print_bsq(void)
{
	int		i;

	i = 0;
	while (i < g_bsq_info->height)
	{
		write(1, g_board->data[i], g_bsq_info->width + 1);
		free(g_board->data[i]);
		free(g_board->solving[i]);
		i++;
	}
	free(g_board->data);
	free(g_board->solving);
}

int		ft_free(void *xavier)
{
	if (xavier == NULL)
		return (NO_MEMORY);
	free(xavier);
	return (PARSE_OK);
}

void	ft_exit(void)
{
	write(2, "map error\n", 10);
	exit(0);
}
