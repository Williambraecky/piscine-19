/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 09:57:35 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/17 11:37:26 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree	*btree_insert(t_btree *current, t_btree *new,
		int (*cmpf)(void *, void *))
{
	if (current == NULL)
		return (new);
	if (cmpf(current->item, new->item) > 0)
		current->left = btree_insert(current->left, new, cmpf);
	else
		current->right = btree_insert(current->right, new, cmpf);
	return (current);
}

void	btree_insert_data(t_btree **root, void *item,
		int (*cmpf)(void *, void *))
{
	t_btree *current;
	t_btree *new;

	new = btree_create_node(item);
	if (*root == NULL)
	{
		*root = new;
		return ;
	}
	current = *root;
	btree_insert(current, new, cmpf);
}
