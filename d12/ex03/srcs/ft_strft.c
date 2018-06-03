/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 16:37:35 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/16 17:55:17 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

t_sp_char		g_sp_char[] =
{
	{'\0', "\\0"},
	{'\a', "\\a"},
	{'\b', "\\b"},
	{'\t', "\\t"},
	{'\n', "\\n"},
	{'\v', "\\v"},
	{'\f', "\\f"},
	{'\r', "\\r"}
};

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putspecialchar(char c)
{
	int i;

	i = 0;
	if (c > 31)
	{
		ft_putchar(c);
		return ;
	}
	while (i < 8)
	{
		if (g_sp_char[i].c == c)
		{
			write(1, g_sp_char[i].str, 2);
			return ;
		}
		i++;
	}
	write(1, " ", 1);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

int		ft_strcmp(char *s1, char *s2)
{
	int		i;
	char	c;
	char	d;

	i = 0;
	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0')
			return (0);
		i++;
	}
	c = s1[i];
	d = s2[i];
	return ((unsigned char)c - (unsigned char)d);
}

char			g_hexbase[] = "0123456789abcdef";

void	ft_putaddress(int addr, int index, int length)
{
	if (index == length)
		return ;
	ft_putaddress(addr / 16, index + 1, length);
	ft_putchar(g_hexbase[addr % 16]);
}
