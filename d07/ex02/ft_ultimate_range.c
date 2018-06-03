/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 08:53:06 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/10 16:48:25 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int *numbers;
	int i;

	if (min >= max)
	{
		range = 0;
		return (0);
	}
	numbers = (int *)malloc(sizeof(int) * (max - min));
	range = (int **)malloc(sizeof(int*) * 1);
	i = 0;
	while (min < max)
	{
		numbers[i] = min;
		min++;
		i++;
	}
	*range = numbers;
	return (i);
}
