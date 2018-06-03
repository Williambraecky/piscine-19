/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_wordtab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 10:54:34 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/14 11:31:00 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2)
{
	char	c;
	char	d;
	int		i;

	i = 0;
	while (*(s1 + i) == *(s2 + i))
	{
		if (*(s1 + i) == '\0')
			return (0);
		i++;
	}
	c = *(s1 + i);
	d = *(s2 + i);
	return ((unsigned char)c - (unsigned char)d);
}

int		ft_tablen(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != 0)
	{
		i++;
	}
	return (i);
}

void	ft_sort_wordtab(char **tab)
{
	int		i;
	int		j;
	char	*c;

	i = ft_tablen(tab) - 1;
	while (i >= 0)
	{
		j = 1;
		while (j <= i)
		{
			if (ft_strcmp(tab[j - 1], tab[j]) > 0)
			{
				c = tab[j];
				tab[j] = tab[j - 1];
				tab[j - 1] = c;
			}
			j++;
		}
		i--;
	}
}
