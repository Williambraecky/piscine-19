/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 14:28:40 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/15 14:30:40 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list *current;

	if (begin_list1 == NULL)
	{
		begin_list1 = &begin_list2;
		return ;
	}
	current = *begin_list1;
	while (current->next != NULL)
		current = current->next;
	current->next = begin_list2;
}
