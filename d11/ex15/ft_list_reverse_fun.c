/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 16:46:27 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/15 17:04:14 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_swap(void **first, void **second)
{
	void *tmp;

	tmp = *first;
	*first = *second;
	*second = tmp;
}

int		ft_list_size(t_list *begin_list)
{
	int i;

	i = 0;
	while (begin_list != NULL)
	{
		begin_list = begin_list->next;
		i++;
	}
	return (i);
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	int		i;
	int		j;
	int		size;
	t_list	*current;
	t_list	*reverse;

	i = 0;
	size = ft_list_size(begin_list);
	current = begin_list;
	while (i < size / 2)
	{
		reverse = current->next;
		j = i + 1;
		while (j++ < size - i - 1)
			reverse = reverse->next;
		ft_swap(&(current->data), &(reverse->data));
		current = current->next;
		i++;
	}
}
