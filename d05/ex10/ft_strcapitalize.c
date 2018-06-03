/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 12:49:06 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/08 16:15:17 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isalphanumeric(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	char	c;
	int		i;

	i = 1;
	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] = str[0] - 32;
	while (str[i])
	{
		c = str[i];
		if (!ft_isalphanumeric(str[i - 1]) && c >= 'a' && c <= 'z')
		{
			if (str[i + 1] != '\0' && !ft_isalphanumeric(str[i + 1]))
				str[i] = c - 32;
		}
		else if (ft_isalphanumeric(str[i - 1]) && c >= 'A' && c <= 'Z')
			str[i] = c + 32;
		i++;
	}
	return (str);
}
