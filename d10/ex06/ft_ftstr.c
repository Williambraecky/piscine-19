/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 09:29:24 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/14 10:32:46 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doop.h"

void	ft_putstr(char *str)
{
	while (*str++)
		ft_putchar(*(str - 1));
}

int		ft_is_numeric(char *str)
{
	int i;

	i = 0;
	while (*(str + i))
	{
		if (*(str + i) < '0' || *(str + i) > '9')
			return (0);
		i++;
	}
	return (1);
}

int		ft_str_equals(char *s1, char *s2)
{
	int i;

	i = 0;
	while (*(s1 + i) == *(s2 + i))
	{
		if (*(s1 + i) == '\0')
			return (1);
		i++;
	}
	return (0);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}
