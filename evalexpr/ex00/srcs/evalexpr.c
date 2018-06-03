/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evalexpr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 09:52:23 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/20 13:52:03 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evalexpr.h"
#include <stdio.h>

char	*g_str;

t_opp	g_opptab[] =
{
	{"+", 0, &ft_add},
	{"-", 0, &ft_sub},
	{"*", 1, &ft_mul},
	{"/", 1, &ft_div},
	{"%", 1, &ft_mod}
};

int		eval_expr(char *str)
{
	g_str = ft_remove_spaces(str);
	return (ft_resolve());
}

int		main(int ac, char *av[])
{
	if (ac > 1)
	{
		ft_putnbr(eval_expr(av[1]));
		ft_putchar('\n');
	}
	return (0);
}
