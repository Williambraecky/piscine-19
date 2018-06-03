/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_wordtab.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 11:32:01 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/14 11:34:41 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_tablen(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != 0)
		i++;
	return (i);
}

void	ft_advanced_sort_wordtab(char **tab, int (*cmp)(char *, char *))
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
			if (cmp(tab[j - 1], tab[j]) > 0)
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
