/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 17:12:28 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/16 18:08:04 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	ft_bad_file_descriptor(char *file)
{
	write(2, "hexdump: ", 9);
	write(2, file, ft_strlen(file));
	write(2, ": Bad file descriptor\n", 22);
}

void	ft_print_error(char *file)
{
	write(2, "hexdump: ", 9);
	write(2, file, ft_strlen(file));
	if (errno == 21)
		write(2, ": Is a directory\n", 17);
	else if (errno == 13)
		write(2, ": Permission denied\n", 20);
	else if (errno == 2)
		write(2, ": No such file or directory\n", 28);
}

int		ft_str_only_space(char *str)
{
	char	c;
	int		i;

	i = 0;
	c = *str;
	while (*(str + i))
	{
		if (*(str + i) != c)
			return (0);
		i++;
	}
	return (1);
}
