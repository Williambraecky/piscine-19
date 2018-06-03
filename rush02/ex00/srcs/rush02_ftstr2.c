/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02_ftstr2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 11:07:18 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/20 11:41:19 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		if (nb == -2147483648)
		{
			ft_putnbr(2);
			ft_putnbr(147483648);
			return ;
		}
		nb = -nb;
	}
	if (nb >= 0 && nb < 10)
	{
		ft_putchar(nb + '0');
		return ;
	}
	ft_putnbr(nb / 10);
	ft_putchar((nb % 10) + '0');
}

int		ft_is_space(char c)
{
	if (c == ' ')
		return (1);
	return (0);
}
