/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 13:02:51 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/03 13:28:54 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *str)
{
	int negative;
	int number;
	int i;

	number = 0;
	if (*str == '\0')
		return 0;
	i = 0;
	if (*str == '-')
	{
		negative = 1;
		i++;
	}
	while(*(str + i))
	{
		number = number * 10 + (*(str + i) - '0');
		i++;
	}
	if (negative)
		number = -number;
	return number;
}
