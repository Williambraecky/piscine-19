/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 17:01:23 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/08 21:32:26 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		ft_strlen(char *base)
{
	int i;

	i = 0;
	while (*(base + i))
		i++;
	return (i);
}

int		ft_verify_base(char *base, int size)
{
	int i;
	int j;

	if (size <= 1)
		return (0);
	i = 0;
	while (i < size)
	{
		j = i + 1;
		if (*(base + i) == '+' || *(base + i) == '-')
			return (0);
		while (j < size)
		{
			if (*(base + i) == *(base + j))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char	ft_translate(int nbr, char *base)
{
	return (*(base + nbr));
}

void	ft_recursive_putnbr_base(int nbr, char *base, int basesize)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr < basesize)
	{
		ft_putchar(ft_translate(nbr, base));
		return ;
	}
	ft_recursive_putnbr_base(nbr / basesize, base, basesize);
	ft_putchar(ft_translate(nbr % basesize, base));
}

void	ft_putnbr_base(int nbr, char *base)
{
	int i;

	i = ft_strlen(base);
	if (!ft_verify_base(base, i))
		return ;
	ft_recursive_putnbr_base(nbr, base, i);
}
