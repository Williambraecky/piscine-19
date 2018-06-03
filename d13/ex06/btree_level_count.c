/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 11:27:22 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/17 11:34:44 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	btree_level_count(t_btree *root)
{
	int i;
	int j;

	if (root == NULL)
		return (0);
	i = 1 + btree_level_count(root->right);
	j = 1 + btree_level_count(root->left);
	return (i > j ? i : j);
}
