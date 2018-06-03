/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 13:02:51 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/08 21:26:51 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_should_skip(char c)
{
	if (c == ' ' || c == '\n' || c == '\t'
			|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int		ft_atoi(char *str)
{
	int negative;
	int number;
	int i;

	i = 0;
	while (*(str + i) && ft_should_skip(*(str + i)))
		i++;
	negative = 0;
	if (*(str + i) == '-' || *(str + i) == '+')
	{
		negative = *(str + i) == '-';
		i++;
	}
	number = 0;
	while (*(str + i))
	{
		if (*(str + i) < '0' || *(str + i) > '9')
			break ;
		number = number * 10 + (*(str + i) - 48);
		i++;
	}
	if (negative)
		number = -number;
	return (number);
}
