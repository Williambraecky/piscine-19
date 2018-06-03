/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 12:26:40 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/08 21:53:44 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strncmp(char *s1, char *s2, unsigned int n)
{
	char			c;
	char			d;
	unsigned	int	i;

	i = 0;
	while (s1[i] == s2[i] && i < n - 1)
	{
		if (s1[i] == '\0')
			return (0);
		i++;
	}
	c = s1[i];
	d = s2[i];
	return ((unsigned char)c - (unsigned char)d);
}
