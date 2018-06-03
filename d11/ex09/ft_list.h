/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 08:22:38 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/15 13:45:47 by wbraeckm         ###   ########.fr       */
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
void					ft_list_push_front(t_list **begin_list, void *data);
int						ft_list_size(t_list *begin_list);
t_list					*ft_list_push_params(int ac, char **av);
void					ft_list_clear(t_list **begin_list);
t_list					*ft_list_at(t_list *begin_list, unsigned int nbr);
void					ft_list_reverse(t_list **begin_list);
void					ft_list_foreach(t_list *begin_list, void (*f)(void *));

#endif
