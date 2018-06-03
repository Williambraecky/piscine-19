/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 16:47:06 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/08 21:34:07 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned	int		ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned	int i;

	i = 0;
	while (*(src + i))
	{
		if (i < size - 1)
			*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = '\0';
	return (i);
}
