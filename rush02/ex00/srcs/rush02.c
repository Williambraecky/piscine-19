/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 12:38:29 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/20 13:37:41 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

t_rush_config	g_rush_configs[] =
{
	{'o', 'o', 'o', 'o', '|', '-'},
	{'/', '\\', '\\', '/', '*', '*'},
	{'A', 'A', 'C', 'C', 'B', 'B'},
	{'A', 'C', 'A', 'C', 'B', 'B'},
	{'A', 'C', 'C', 'A', 'B', 'B'}
};

t_checks		g_check_registry[] =
{
	{"carre", &ft_check_square},
	{"rectangle", &ft_check_rectangle},
	{"carre inverse", &ft_check_square_rev},
	{"rectangle inverse", &ft_check_rev_rectangle}
};

void			ft_print_result(char *name, int width, int height, int nb)
{
	if (nb > 0)
		write(1, " || ", 4);
	write(1, "[", 1);
	write(1, name, ft_strlen(name));
	write(1, "] [", 3);
	ft_putnbr(width);
	write(1, "] [", 3);
	ft_putnbr(height);
	write(1, "]", 1);
}

void			ft_print_result_colle(int colle, int j, char *str)
{
	if (j > 0)
		write(1, " || ", 4);
	write(1, "[colle-0", 8);
	ft_putnbr(colle);
	write(1, "] [", 3);
	ft_putnbr(ft_get_line_width(str));
	write(1, "] [", 3);
	ft_putnbr(ft_count_lines(str));
	write(1, "]", 1);
}

void			ft_check_registry(char *input, int nb)
{
	t_checks	check;
	int			i;

	i = 0;
	while (i < 4)
	{
		check = g_check_registry[i];
		if (check.ft(input) == MATCHING_STRUCTURE)
		{
			ft_print_result(check.name, ft_get_line_width(input),
					ft_count_lines(input), nb);
			nb++;
		}
		i++;
	}
	if (nb == 0)
		write(1, "aucune\n", 7);
	else
		write(1, "\n", 1);
}

void			ft_check_results(char *input)
{
	int result;
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 5)
	{
		result = ft_check_rush(g_rush_configs[i], input);
		if (result == INVALID_STRUCTURE)
			break ;
		if (result == INVALID_CHAR)
		{
			i++;
			continue ;
		}
		if (result == MATCHING_STRUCTURE)
			ft_print_result_colle(i, j++, input);
		i++;
	}
	ft_check_registry(input, j);
}

int				main(int argc, char *argv[])
{
	char *str;

	if (argc == 0 && !(argv[0][0] != 'c'))
		return (0);
	str = ft_parse_previous_input();
	if (str == NULL)
		write(1, "aucune\n", 7);
	else
		ft_check_results(str);
	return (0);
}
