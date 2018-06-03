/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 11:13:12 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/04 12:13:39 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_factorial(int nb)
{
	int i;
	int count;

	if (nb < 0)
		return 0;
	if (nb == 0)
		return 1;
	i = nb;
	count = 1;
	while (i > 1)
	{
		count = count * i;
		if (count < 0)
			return 0;
		i--;
	}
	return count;
}
