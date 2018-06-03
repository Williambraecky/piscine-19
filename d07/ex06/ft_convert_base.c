/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 15:21:47 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/10 13:12:32 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
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

int		ft_str_to_int_base(char *str, char *base)
{
	int number;
	int negative;
	int i;
	int base_size;

	i = 0;
	negative = *(str + i) == '-';
	if (*(str + i) == '-' || *(str + i) == '+')
		i++;
	number = 0;
	base_size = ft_strlen(base);
	while (*(str + i))
	{
		number = number * base_size + (ft_base_translate(*(str + i), base));
		i++;
	}
	if (negative)
		number = -number;
	return (number);
}

char	*ft_int_to_str_base(int nbr, char *base)
{
	char	*result;
	int		base_size;
	int		str_size;
	int		i;
	int		negative;

	base_size = ft_strlen(base);
	negative = nbr < 0;
	if (nbr < 0)
		nbr = -nbr;
	str_size = 1;
	i = nbr;
	while (i / base_size >= base_size && str_size++)
		i = i / base_size;
	result = (char *)malloc(sizeof(char) * (negative + str_size + 1));
	i = str_size + negative;
	while (nbr > 0)
	{
		result[i--] = *(base + nbr % base_size);
		nbr /= base_size;
	}
	if (negative)
		result[0] = '-';
	result[str_size + 1 + negative] = '\0';
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*result;
	int		i;

	if (ft_strlen(base_from) < 2 || ft_strlen(base_to) < 2)
		return (0);
	i = ft_str_to_int_base(nbr, base_from);
	result = ft_int_to_str_base(i, base_to);
	return (result);
}
