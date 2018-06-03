/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 11:38:46 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/17 15:03:47 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_linked	*ft_create_list_elem(t_btree *data, int level)
{
	t_linked *new;

	new = (t_linked *)malloc(sizeof(t_linked));
	if (new != NULL)
	{
		new->branch = data;
		new->level = level;
		new->next = NULL;
	}
	return (new);
}

void		ft_list_push_back(t_linked **list, t_btree *data, int level)
{
	t_linked *last;

	if (*list == NULL)
	{
		*list = ft_create_list_elem(data, level);
		return ;
	}
	last = *list;
	while (last->next != NULL)
		last = last->next;
	last->next = ft_create_list_elem(data, level);
}

void		btree_apply_by_level_with_level(t_btree *root,
		int current_level, t_linked *list)
{
	if (root == NULL)
		return ;
	if (root->left != NULL)
		ft_list_push_back(&list, root->left, current_level + 1);
	if (root->right != NULL)
		ft_list_push_back(&list, root->right, current_level + 1);
}

void		btree_apply_to_list(t_linked **list,
		void (*applyf)(void *item, int current_level, int is_first_elem))
{
	t_linked	*current;
	int			prev_level;
	int			first;

	current = *list;
	prev_level = -1;
	while (current != NULL)
	{
		if (prev_level != current->level)
			first = 1;
		prev_level = current->level;
		applyf(current->branch->item, current->level, first);
		first = 0;
		current = current->next;
	}
}

void		btree_apply_by_level(t_btree *root,
		void (*applyf)(void *item, int current_level, int is_first_elem))
{
	t_linked	*list;
	t_linked	*current;
	int			prev_level;

	if (root == NULL)
		return ;
	list = NULL;
	ft_list_push_back(&list, root, 0);
	current = list;
	prev_level = 0;
	while (current != NULL)
	{
		if (current->level != prev_level)
			prev_level++;
		btree_apply_by_level_with_level(current->branch, prev_level, list);
		current = current->next;
	}
	btree_apply_to_list(&list, applyf);
}
