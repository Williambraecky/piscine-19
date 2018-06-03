/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 09:31:13 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/16 09:13:12 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	t_list				*current;
	unsigned	int		i;

	i = 0;
	if (begin_list == NULL)
		return (NULL);
	current = begin_list;
	while (current != NULL)
	{
		if (nbr == i)
			return (current);
		current = current->next;
	}
	return (NULL);
}
