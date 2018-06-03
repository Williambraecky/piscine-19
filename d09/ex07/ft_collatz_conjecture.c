/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collatz_conjecture.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 00:22:41 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/11 00:30:01 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_collatz_conjecture(unsigned int base)
{
	int i;

	i = 0;
	while (base != 1)
	{
		if (base % 2 == 0)
		{
			base = base / 2;
		}
		else
		{
			base = base * 3 + 1;
		}
		i++;
	}
	return (i);
}
