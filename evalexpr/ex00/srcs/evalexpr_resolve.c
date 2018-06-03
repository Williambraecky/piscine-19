/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evalexpr_resolve.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 11:16:46 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/20 13:52:10 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evalexpr.h"

extern char *g_str;

int		ft_next_sum(void)
{
	int i;

	if (*g_str >= '0' && *g_str <= '9')
		return (ft_next_number());
	else if (*g_str == '(')
	{
		g_str++;
		i = ft_resolve();
		g_str++;
		return (i);
	}
	else if (*g_str == '-')
	{
		g_str++;
		return (-(ft_next_number()));
	}
	return (0);
}

int		ft_factors(void)
{
	int i;

	i = ft_next_sum();
	while (ft_get_operation(*g_str) != NULL
			&& ft_get_operation(*g_str)->priority == 1)
		i = ft_next_operation()->opp(i, ft_next_sum());
	return (i);
}

int		ft_sums(void)
{
	int i;

	i = ft_factors();
	while (ft_get_operation(*g_str) != NULL
			&& ft_get_operation(*g_str)->priority == 0)
		i = ft_next_operation()->opp(i, ft_factors());
	return (i);
}

int		ft_resolve(void)
{
	return (ft_sums());
}
