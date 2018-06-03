/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 12:57:21 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/03 13:00:17 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (*(str + i))
	{
		i++;
	}
	return i;
}

char	*ft_strrev(char *str)
{
	int size;
	int i;
	int j;
	char c;

	size = ft_strlen(str);
	i = 0;
	j = size - 1;
	while (i < size / 2)
	{
		c = str[i];
		str[i] = str[j];
		str[j] = c;
		i++;
		j--;
	}
	return str;
}
