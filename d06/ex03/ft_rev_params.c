/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 12:50:43 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/08 13:01:17 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	while (*str++)
		ft_putchar(*(str - 1));
}

int		main(int i, char **argv)
{
	int j;

	j = i - 1;
	while (j > 0)
	{
		ft_putstr(argv[j]);
		ft_putchar('\n');
		j--;
	}
}
