/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 13:02:10 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/08 15:44:33 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_putchar(char c);

int		ft_strcmp(char *s1, char *s2)
{
	char	c;
	char	d;
	int		i;

	i = 0;
	while (*(s1 + i) == *(s2 + i))
	{
		if (*(s1 + i) == '\0')
			return (0);
		i++;
	}
	c = *(s1 + i);
	d = *(s2 + i);
	return ((unsigned char)c - (unsigned char)d);
}

void	ft_putstr(char *str)
{
	while (*str++)
		ft_putchar(*(str - 1));
}

void	ft_sort_str_table(char *table[], int size)
{
	int		i;
	int		j;
	char	*c;

	i = size - 1;
	while (i >= 1)
	{
		j = 2;
		while (j <= i)
		{
			if (ft_strcmp(table[j - 1], table[j]) > 0)
			{
				c = table[j];
				table[j] = table[j - 1];
				table[j - 1] = c;
			}
			j++;
		}
		i--;
	}
}

int		main(int i, char *argv[])
{
	int		j;

	if (i <= 1)
		return (0);
	ft_sort_str_table(argv, i);
	j = 1;
	while (j < i)
	{
		ft_putstr(argv[j++]);
		ft_putchar('\n');
	}
}
