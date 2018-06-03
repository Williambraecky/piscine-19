/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 09:25:57 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/14 10:33:35 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doop.h"

int		ft_is_operation_char(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}

void	(*ft_read_operation(char *str)) (int, int)
{
	int		i;
	void	(*f[5]) (int, int);
	char	*tab;

	if (ft_strlen(str) != 1 || !ft_is_operation_char(*str))
		return (0);
	f[0] = &ft_add;
	f[1] = &ft_remove;
	f[2] = &ft_multiply;
	f[3] = &ft_divide;
	f[4] = &ft_modulo;
	tab = "+-*/%";
	i = 0;
	while (i < 5)
	{
		if (*str == tab[i])
			return (f[i]);
		i++;
	}
	return (0);
}

int		main(int argc, char *argv[])
{
	int		i;
	int		j;
	void	(*f)(int, int);

	if (argc != 4)
		return (0);
	i = ft_atoi(argv[1]);
	f = ft_read_operation(argv[2]);
	j = ft_atoi(argv[3]);
	if (f == 0)
	{
		write(1, "0", 1);
		return (0);
	}
	f(i, j);
	ft_putchar('\n');
	return (0);
}
