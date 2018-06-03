/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_words_tables.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 14:53:47 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/09 15:20:02 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	while (*str++)
		ft_putchar(*(str - 1));
}

void	ft_print_words_tables(char **tab)
{
	int i;

	i = 0;
	while (*(tab + i) != 0)
	{
		ft_putstr(*(tab + i));
		ft_putchar('\n');
		i++;
	}
}
