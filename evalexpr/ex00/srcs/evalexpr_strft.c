/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evalexpr_strft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 09:54:20 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/19 11:59:17 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evalexpr.h"

extern t_opp	g_opptab[];
extern char		*g_str;

t_opp			*ft_get_operation(char c)
{
	int i;

	i = 0;
	while (i < 5)
	{
		if (g_opptab[i].str[0] == c)
			return (&(g_opptab[i]));
		i++;
	}
	return (NULL);
}

t_opp			*ft_next_operation(void)
{
	return (ft_get_operation(*(g_str++)));
}

int				ft_is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int				ft_next_number(void)
{
	int i;

	i = 0;
	while (*g_str >= '0' && *g_str <= '9')
	{
		i = i * 10 + (*g_str - '0');
		g_str++;
	}
	return (i);
}

char			*ft_remove_spaces(char *str)
{
	int j;
	int i;

	i = 0;
	j = 0;
	while (*(str + j))
	{
		if (!ft_is_space(*(str + j)))
			str[i++] = *(str + j);
		j++;
	}
	str[i] = '\0';
	return (str);
}
