/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens_puzzle.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 14:58:20 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/05 17:21:11 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_array(int *queens)
{
	int i;

	i = 0;
	while (i < 8)
		ft_putchar(queens[i++] + '1');
	ft_putchar('\n');
}

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

void	ft_try_queens(int *queens, int position)
{
	int i;

	if (position == 8)
		ft_print_array(queens);
	i = 0;
	while (i < 8)
	{
		queens[position] = i++;
		if (ft_check_placement(queens, position))
			ft_try_queens(queens, position + 1);
	}
}

void	ft_eight_queens_puzzle_2(void)
{
	int queens[8];

	ft_try_queens(queens, 0);
}
