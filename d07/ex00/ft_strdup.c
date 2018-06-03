/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 08:29:34 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/10 16:40:52 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*dup;
	int		i;

	i = 0;
	while (*(src + i))
		i++;
	dup = (char *)malloc(sizeof(char) * i);
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (*(src + i))
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
