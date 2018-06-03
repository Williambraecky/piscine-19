/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 13:04:10 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/19 16:36:53 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

t_list	*ft_create_new_elem(char *str, int size)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new != NULL)
	{
		new->str = ft_strdup(str);
		new->size = size;
		new->next = NULL;
	}
	return (new);
}

void	ft_list_push_back(t_list **begin_list, char *str, int size)
{
	t_list *start;

	if (*begin_list == NULL)
	{
		*begin_list = ft_create_new_elem(str, size);
		return ;
	}
	start = *begin_list;
	while (start->next != NULL)
		start = start->next;
	start->next = ft_create_new_elem(str, size);
}

int		ft_list_total_size(t_list *start)
{
	int i;

	i = 0;
	while (start != NULL)
	{
		i += start->size;
		start = start->next;
	}
	i++;
	return (i);
}

char	*ft_list_combine(t_list *start)
{
	char	*result;
	int		i;

	if (start == NULL)
		return (NULL);
	result = (char *)malloc(sizeof(char) * ft_list_total_size(start));
	result[ft_list_total_size(start) - 1] = '\0';
	i = 0;
	while (start != NULL)
	{
		ft_strcat(result, start->str, i);
		i += start->size;
		start = start->next;
	}
	return (result);
}

char	*ft_parse_previous_input(void)
{
	char	buffer[256 + 1];
	t_list	*list;
	int		j;

	list = NULL;
	while ((j = read(0, buffer, 256)) > 0)
	{
		buffer[j] = '\0';
		ft_list_push_back(&list, buffer, j);
	}
	return (ft_list_combine(list));
}
