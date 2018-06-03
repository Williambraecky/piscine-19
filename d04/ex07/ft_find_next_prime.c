/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 14:36:39 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/04 14:56:55 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_prime(int nb)
{
	int i;	

	if (nb == 2 || nb == 3)
		return 1;
	if (nb <= 1 || nb % 2 == 0 || nb % 3 == 0)
	   return 0;
	i = 5;
	while (i < nb / 2)
	{
		if (nb % i == 0 || nb % (i + 2) == 0)
			return 0;
		i = i + 4;
	}
	return 1;
}

int		ft_find_next_prime(int nb)
{
	while (ft_is_prime(nb) == 0)
		nb++;
	return nb;
}
