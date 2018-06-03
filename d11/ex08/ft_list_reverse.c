/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 10:53:56 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/15 16:45:48 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list *prev;
	t_list *current;
	t_list *tmp;

	if (begin_list == NULL || (*begin_list)->next == NULL)
		return ;
	current = *begin_list;
	prev = current;
	tmp = current->next;
	current->next = NULL;
	current = tmp;
	while (current != NULL)
	{
		tmp = current->next;
		current->next = prev;
		prev = current;
		current = tmp;
	}
	*begin_list = prev;
}
