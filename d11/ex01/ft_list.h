/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 08:22:38 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/15 08:56:16 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include <stdlib.h>

typedef struct s_list	t_list;

struct					s_list
{
	void				*data;
	t_list				*next;
};

t_list					*ft_create_elem(void *data);
void					ft_list_push_back(t_list **begin_data, void *data);

#endif
