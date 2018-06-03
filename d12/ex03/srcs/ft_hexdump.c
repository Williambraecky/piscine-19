/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 15:34:10 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/16 18:14:44 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"
#include <stdio.h>

void	ft_hexdump_print_char(char *bus, int max)
{
	int i;

	i = 0;
	while (i < 16)
	{
		if (i < max)
		{
			if (bus[i] > 31)
				write(1, "   ", 3);
			else
				write(1, "  ", 2);
			ft_putspecialchar(bus[i]);
		}
		else
			write(1, "    ", 4);
		i++;
	}
	write(1, "\n", 1);
}

int		ft_handle_file(int fd, char bus[], int k)
{
	int prev_only_spaces;
	int j;
	int l;

	l = 0;
	prev_only_spaces = 0;
	while ((j = read(fd, bus, 16)) > 0)
	{
		if (ft_str_only_space(bus) && prev_only_spaces && (k += j) > 0)
		{
			if (l == 0)
				write(1, "*\n", 2);
			l = 1;
			continue ;
		}
		l = 0;
		bus[j] = '\0';
		prev_only_spaces = ft_str_only_space(bus);
		ft_putaddress((k += j) - j, 0, 7);
		ft_hexdump_print_char(bus, j);
	}
	if (k > 0)
		ft_putaddress(k, 0, 7);
	return (k);
}

void	ft_hexdump_read_files(int filecount, char **files)
{
	char	bus[16 + 1];
	int		fd;
	int		k;
	int		i;

	i = 1;
	k = 0;
	while (++i < filecount)
	{
		fd = open(files[i], O_RDWR);
		if (errno != 0)
		{
			ft_print_error(files[i]);
			if (errno != 21)
				ft_bad_file_descriptor(files[i]);
			continue ;
		}
		k = ft_handle_file(fd, bus, k);
	}
	if (k > 0)
		write(1, "\n", 1);
}

int		main(int argc, char **argv)
{
	if (argc <= 2)
	{
		write(2, "Invalid number of arguments\n", 28);
		return (0);
	}
	if (ft_strcmp(argv[1], "-c") != 0)
	{
		write(2, "Invalid flag\n", 13);
		return (0);
	}
	ft_hexdump_read_files(argc, argv);
	return (0);
}
