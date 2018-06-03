/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:07:12 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/15 17:18:28 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list *current;
	t_list *insert;
	t_list *prev;

	current = *begin_list;
	insert = ft_create_elem(data);
	if (cmp(current->data, data) > 0)
	{
		insert->next = current;
		*begin_list = insert;
		return ;
	}
	while (current->next != NULL)
	{
		if (cmp(current->data, data) > 0)
		{
			prev->next = insert;
			insert->next = current;
			return ;
		}
		prev = current;
		current = current->next;
	}
	current->next = insert;
}
