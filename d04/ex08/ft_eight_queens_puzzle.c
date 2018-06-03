/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens_puzzle.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 14:58:20 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/05 17:23:46 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_check_placement(int *queens, int position)
{
	int i;
	int queen;
	int queen2;

	i = 0;
	queen = queens[position];
	while (i < position)
	{
		queen2 = queens[i];
		if (queen == queen2)
			return 0;
		if (queen - queen2 == position - i)
			return 0;
		if (queen2 - queen == position - i)
			return 0;
		i++;
	}
	return 1;
}

int		ft_try_queens(int *queens, int position)
{
	int i;
	int count;

	if (position == 8)
		return 1;
	i = 0;
	count = 0;
	while (i < 8)
	{
		queens[position] = i++;
		if (ft_check_placement(queens, position))
			if (ft_try_queens(queens, position + 1))
				count = count + ft_try_queens(queens, position + 1);
	}
	return count;
}

int		ft_eight_queens_puzzle(void)
{
	int queens[8];

	return ft_try_queens(queens, 0);
}
