/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 11:41:31 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/03 07:48:14 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		if (nb == -2147483648)
		{
			ft_putnbr(2);
			ft_putnbr(147483648);
			return;
		}
		n = -n;
	}
	if (n >= 0 && n < 10)
	{
		ft_putchar(n + '0');
		return;
	}
	ft_putnbr(n / 10);
	ft_putchar((n % 10) + '0');
}
