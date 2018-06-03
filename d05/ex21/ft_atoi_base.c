/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 18:08:23 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/09 11:35:50 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

int		ft_check_multiples(char *base)
{
	int i;
	int j;

	if (ft_strlen(base) < 1)
		return (0);
	i = 0;
	while (*(base + i))
	{
		j = i + 1;
		if (*(base + i) == '-' || *(base + i) == '+')
			return (0);
		while (*(base + j))
		{
			if (*(base + i) == *(base + j))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_check_str_base(char *str, char *base)
{
	int i;
	int j;
	int flag;

	i = 0;
	flag = 1;
	while (*(str + i))
	{
		j = 0;
		flag = 0;
		while (*(base + j))
		{
			if (*(str + i) == *(base + j))
			{
				flag = 1;
			}
			j++;
		}
		i++;
	}
	return ((flag) && ft_check_multiples(base));
}

int		ft_base_translate(char c, char *base)
{
	int i;

	i = 0;
	while (*(base + i))
	{
		if (c == *(base + i))
			return (i);
		i++;
	}
	return (0);
}

int		ft_atoi_base(char *str, char *base)
{
	int number;
	int negative;
	int i;
	int size;

	i = 0;
	if (!ft_check_str_base(str, base))
		return (0);
	while (*(str + i) && *(str + i) == ' ')
		i++;
	negative = *(str + i) == '-';
	if (*(str + i) == '-' || *(str + i) == '+')
		i++;
	number = 0;
	size = ft_strlen(base);
	while (*(str + i))
	{
		number = number * size + (ft_base_translate(*(str + i), base));
		i++;
	}
	if (negative)
		number = -number;
	return (number);
}
