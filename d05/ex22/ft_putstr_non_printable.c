/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 19:09:23 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/08 19:47:55 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		ft_is_non_printable(char c)
{
	if (c <= 31)
		return (1);
	return (0);
}

void	ft_putchar_non_printable(char c, char *hexbase)
{
	ft_putchar('\\');
	ft_putchar(hexbase[c / 16]);
	ft_putchar(hexbase[c % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	char	base[16];
	int		i;

	i = 0;
	while (i < 16)
	{
		if (i < 10)
			base[i] = i + '0';
		else
			base[i] = i + 87;
		i++;
	}
	i = 0;
	while (*(str + i))
	{
		if (ft_is_non_printable(*(str + i)))
			ft_putchar_non_printable(*(str + i), base);
		else
			ft_putchar(*(str + i));
		i++;
	}
}
