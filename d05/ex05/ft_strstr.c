/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 10:53:47 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/08 21:57:02 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;
	int k;
	int l;

	if (to_find[0] == '\0')
		return (str);
	i = ft_strlen(str);
	j = ft_strlen(to_find);
	if (j > i)
		return (0);
	k = -1;
	while (++k < i - j + 1)
	{
		if (str[k] == to_find[0])
		{
			l = -1;
			while (++l < j)
				if (str[k + l] != to_find[l])
					break ;
			return (str + k);
		}
	}
	return (0);
}
