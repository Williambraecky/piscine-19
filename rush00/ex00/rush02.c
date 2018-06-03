/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 17:57:17 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/06 14:34:09 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

char	ft_getchar(int x, int y, int i, int j)
{
	if (j == 0 && (i == 0 || i == x - 1))
		return ('A');
	else if (j == y - 1 && (i == 0 || i == x - 1))
		return ('C');
	else if (i == 0 || i == x - 1)
		return ('B');
	else if (j == 0 || j == y - 1)
		return ('B');
	return (' ');
}

void	rush(int x, int y)
{
	int i;
	int j;

	if (x < 0 || y < 0)
		return ;
	j = 0;
	while (j < y)
	{
		i = 0;
		while (i < x)
		{
			ft_putchar(ft_getchar(x, y, i, j));
			i++;
		}
		ft_putchar('\n');
		j++;
	}
}
