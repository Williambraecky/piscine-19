/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 08:27:54 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/15 08:56:04 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *last;

	last = *begin_list;
	if (begin_list == NULL)
	{
		*begin_list = ft_create_elem(data);
		return ;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = ft_create_elem(data);
}
