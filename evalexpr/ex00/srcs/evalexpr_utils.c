/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evalexpr_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 10:56:01 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/20 11:00:41 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evalexpr.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int i)
{
	if (i < 0)
	{
		ft_putchar('-');
		if (i == -2147483648)
		{
			ft_putnbr(2);
			ft_putnbr(147483648);
			return ;
		}
		i = -i;
	}
	if (i >= 0 && i < 10)
	{
		ft_putchar(i + '0');
		return ;
	}
	ft_putnbr(i / 10);
	ft_putchar((i % 10) + '0');
}
