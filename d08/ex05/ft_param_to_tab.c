/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 19:54:30 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/10 20:33:23 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"
#include <stdlib.h>
#include <stdio.h>

char				**ft_split_whitespaces(char *str);

int					ft_strlen(char *str)
{
	int i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

char				*ft_strdup(char *str)
{
	char	*dup;
	int		i;

	i = ft_strlen(str);
	dup = (char *)malloc(sizeof(char) * i);
	i = 0;
	while (*(str + i))
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

struct	s_stock_par	*ft_param_to_tab(int ac, char **av)
{
	t_stock_par	*result;
	t_stock_par	current;
	int			i;

	result = (t_stock_par *)malloc(sizeof(t_stock_par) * ac);
	i = 0;
	while (i < ac)
	{
		current.size_param = ft_strlen(av[i]);
		current.str = av[i];
		current.copy = ft_strdup(av[i]);
		current.tab = ft_split_whitespaces(av[i]);
		result[i] = current;
		i++;
	}
	result[i].str = 0;
	return (result);
}
