/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 14:19:00 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/15 14:26:23 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *current;
	t_list *prev;

	if (begin_list == NULL)
		return ;
	current = *begin_list;
	while (current != NULL)
	{
		if (cmp(current->data, data_ref) == 0)
		{
			if (current == *begin_list)
			{
				begin_list = &current->next;
			}
			else
			{
				prev->next = current->next;
			}
		}
		prev = current;
		current = current->next;
	}
}
