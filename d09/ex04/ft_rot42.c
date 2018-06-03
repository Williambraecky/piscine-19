/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot42.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 23:03:41 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/10 23:40:18 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_char_isalpha(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

char	ft_rot_char(char c, int rotations)
{
	int i;

	i = 0;
	while (i < rotations)
	{
		if (c == 'z')
			c = 'a';
		else if (c == 'Z')
			c = 'A';
		else
			c++;
		i++;
	}
	return (c);
}

char	*ft_rot42(char *str)
{
	int i;

	i = 0;
	while (*(str + i))
	{
		if (ft_char_isalpha(*(str + i)))
			str[i] = ft_rot_char(*(str + i), 13);
		i++;
	}
	return (str);
}
