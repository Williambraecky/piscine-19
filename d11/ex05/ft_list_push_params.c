/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 09:09:52 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/15 10:24:41 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_params(int ac, char **av)
{
	t_list	*result;
	int		i;

	if (ac <= 1)
		return (NULL);
	i = 1;
	result = NULL;
	while (i < ac)
	{
		if (result == NULL)
			result = ft_create_elem(av[i]);
		else
			ft_list_push_front(&result, av[i]);
		i++;
	}
	return (result);
}
