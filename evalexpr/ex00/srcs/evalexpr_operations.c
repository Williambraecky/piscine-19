/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evalexpr_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 10:09:55 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/19 10:12:21 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evalexpr.h"

int	ft_add(int i, int j)
{
	return (i + j);
}

int	ft_sub(int i, int j)
{
	return (i - j);
}

int	ft_mul(int i, int j)
{
	return (i * j);
}

int	ft_div(int i, int j)
{
	return (i / j);
}

int	ft_mod(int i, int j)
{
	return (i % j);
}
