/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 12:12:02 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/04 12:24:04 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_factorial(int nb)
{
	int result;

	if (nb < 0)
		return 0;
	if (nb == 0)
		return 1;
	result = nb * ft_recursive_factorial(nb - 1);
	if (result < 0)
		return 0;
	return result;
}
