/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouvroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 17:52:27 by nrouvroy          #+#    #+#             */
/*   Updated: 2018/05/23 11:42:51 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_listpushback(t_list **blist, char buf)
{
	t_list	*list;

	if (*blist == NULL)
	{
		list = malloc(sizeof(t_list));
		if (list == NULL)
			ft_exit();
		list->data = buf;
		list->next = NULL;
		*blist = list;
	}
	else
	{
		list = *blist;
		while (list->next != NULL)
			list = list->next;
		list->next = malloc(sizeof(t_list));
		list = list->next;
		if (list == NULL)
			ft_exit();
		list->data = buf;
		list->next = NULL;
	}
}

char	ft_listpop(t_list **blist)
{
	t_list	*current;
	char	c;

	current = *blist;
	if (current == NULL)
		return (0);
	if (current->next == NULL)
	{
		*blist = NULL;
		return (current->data);
	}
	while (current->next->next != NULL)
		current = current->next;
	c = current->next->data;
	free(current->next);
	current->next = NULL;
	return (c);
}

int		ft_listint(t_list **blist)
{
	int		i;
	t_list	*current;

	i = 0;
	current = *blist;
	while (current != NULL)
	{
		if (current->data < '0' || current->data > '9')
			ft_exit();
		i = i * 10 + (current->data - '0');
		current = current->next;
	}
	return (i);
}

int		ft_listlen(t_list *blist)
{
	int		i;

	i = 1;
	if (blist == NULL)
		return (0);
	while (blist != NULL)
	{
		blist = blist->next;
		i++;
	}
	return (i);
}

char	*ft_listgetbuf(t_list **blist)
{
	int		i;
	t_list	*list;
	char	*buf;

	buf = (char *)malloc(sizeof(char) * ft_listlen(*blist));
	if (buf == NULL)
		ft_exit();
	list = *blist;
	i = 0;
	while (list != NULL)
	{
		*(buf + i) = list->data;
		list = list->next;
		i++;
	}
	return (buf);
}
