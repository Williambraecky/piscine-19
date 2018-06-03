/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 12:39:17 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/08 12:57:16 by wbraeckm         ###   ########.fr       */
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

	j = 1;
	while (j < i)
	{
		ft_putstr(argv[j]);
		ft_putchar('\n');
		j++;
	}
}
