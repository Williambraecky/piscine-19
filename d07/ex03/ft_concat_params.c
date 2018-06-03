/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 09:22:45 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/10 16:51:11 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

int		ft_count_char(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		j += ft_strlen(argv[i]);
		i++;
	}
	return (j);
}

char	*ft_concat_params(int argc, char **argv)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	if (argc <= 1)
		return (0);
	k = ft_count_char(argc, argv);
	str = (char *)malloc(sizeof(char) * (k + argc - 2));
	i = 1;
	k = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
			str[k++] = argv[i][j++];
		if (i != argc - 1)
			str[k++] = '\n';
		i++;
	}
	str[k] = '\0';
	return (str);
}
