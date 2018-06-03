/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 09:30:00 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/17 09:33:56 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree	*btree_create_node(void *item)
{
	t_btree *branch;

	branch = (t_btree *)malloc(sizeof(t_btree));
	if (branch != NULL)
	{
		branch->item = item;
		branch->left = NULL;
		branch->right = NULL;
	}
	return (branch);
}
