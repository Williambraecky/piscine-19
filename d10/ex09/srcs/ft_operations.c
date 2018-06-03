/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 09:21:31 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/14 12:30:40 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doop.h"

void	ft_add(int i, int j)
{
	ft_putnbr(i + j);
}

void	ft_sub(int i, int j)
{
	ft_putnbr(i - j);
}

void	ft_mul(int i, int j)
{
	ft_putnbr(i * j);
}

void	ft_div(int i, int j)
{
	if (j == 0)
		ft_putstr("Stop : division by zero");
	else
		ft_putnbr(i / j);
}

void	ft_mod(int i, int j)
{
	if (j == 0)
		ft_putstr("Stop : modulo by zero");
	else
		ft_putnbr(i % j);
}
