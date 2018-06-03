/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_integer_table.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 13:29:39 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/03 14:00:10 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int i;

	i = *a;
	*a = *b;
	*b = i;
}

void	ft_sort_integer_table(int *tab, int size)
{
	int	i;
	int j;

	i = size - 1;
	while (i >= 0)
	{
		j = 1;
		while (j <= i)
		{
			if (tab[j - 1] > tab[j])
				ft_swap(&tab[j - 1], &tab[j]);
			j++;
		}
		i--;
	}
}
