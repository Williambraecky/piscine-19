/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 08:35:12 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/15 08:54:58 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *new;

	if (begin_list == NULL)
	{
		*begin_list = ft_create_elem(data);
		return ;
	}
	new = ft_create_elem(data);
	new->next = *begin_list;
	*begin_list = new;
}
