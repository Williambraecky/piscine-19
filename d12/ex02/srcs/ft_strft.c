/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 13:11:15 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/16 18:25:38 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str++)
		ft_putchar(*(str - 1));
}

int		ft_strcmp(char *s1, char *s2)
{
	char	c;
	char	d;
	int		i;

	i = 0;
	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0')
			return (0);
		i++;
	}
	c = s1[i];
	d = s1[i];
	return ((unsigned char)c - (unsigned char)d);
}

void	ft_put_tail_header(char *file)
{
	write(1, "==> ", 4);
	write(1, file, ft_strlen(file));
	write(1, " <==\n", 5);
}
