/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:16:38 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/16 09:19:38 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int		ft_swap_t_list(t_list *a, t_list *b)
{
	void *data;

	data = a->data;
	a->data = b->data;
	b->data = data;
	return (1);
}

t_list	*ft_list_get_last(t_list *start)
{
	t_list *current;

	current = start;
	while (current->next != NULL)
		current = current->next;
	return (current);
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	int		change;
	t_list	*current;
	t_list	*end;

	if (begin_list == NULL)
		return ;
	change = 1;
	end = NULL;
	while (change > 0)
	{
		change = 0;
		current = *begin_list;
		while (current->next != end)
		{
			if (cmp(current->data, current->next->data) > 0)
				change += ft_swap_t_list(current, current->next);
			current = current->next;
		}
		end = current;
	}
}

void	ft_list_merge(t_list *list1, t_list *list2)
{
	while (list1->next != NULL)
		list1 = list1->next;
	list1->next = list2;
}

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
		int (*cmp)())
{
	if (begin_list1 == NULL && begin_list2 == NULL)
		return ;
	if (begin_list1 == NULL)
	{
		begin_list1 = &begin_list2;
		ft_list_sort(begin_list1, cmp);
	}
	else if (begin_list2 == NULL)
	{
		ft_list_sort(begin_list1, cmp);
	}
	else
	{
		ft_list_merge(*begin_list1, begin_list2);
		ft_list_sort(begin_list1, cmp);
	}
}
