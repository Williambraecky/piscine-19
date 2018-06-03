/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 09:08:16 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/14 09:13:32 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** On commence a un parce qu'on doit juste comparer par rapport au precedent
** et index 0 n'a pas de precedent
*/

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;

	i = 1;
	while (i < length)
	{
		if (f(tab[i - 1], tab[i]) > 0)
			return (0);
		i++;
	}
	return (1);
}
