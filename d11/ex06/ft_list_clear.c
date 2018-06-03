/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 09:24:47 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/15 09:28:18 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_clear(t_list **begin_list)
{
	t_list *current;
	t_list *tmp;

	if (begin_list == NULL)
		return ;
	current = *begin_list;
	while (current != NULL)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
}
