/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 09:25:57 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/14 12:31:29 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doop.h"
#include "ft_opp.h"

extern t_opp g_opptab[6];

int		ft_is_operation_char(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}

void	ft_usage(int i, int j)
{
	if (i == j)
		ft_putstr("error : only [ + - * / %] are accepted.");
	else
		ft_putstr("error : only [ + - * / %] are accepted.");
}

void	(*ft_read_operation(char *str)) (int, int)
{
	int		i;

	if (ft_strlen(str) != 1 || !ft_is_operation_char(*str))
		return (g_opptab[5].fptr);
	i = 0;
	while (i < 5)
	{
		if (ft_str_equals(str, g_opptab[i].str))
			return (g_opptab[i].fptr);
		i++;
	}
	return (g_opptab[5].fptr);
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
	f(i, j);
	ft_putchar('\n');
	return (0);
}
