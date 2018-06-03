/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 12:13:03 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/16 18:32:23 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

void	ft_print_error(char *file)
{
	write(2, "tail: ", 6);
	write(2, file, ft_strlen(file));
	if (errno == 2)
		write(2, ": No such file or directory\n", 28);
	else if (errno == 13)
		write(2, ": Permission denied\n", 20);
}

void	ft_shift_insert(char bus[], char c, int length)
{
	int i;

	i = 0;
	while (i < length - 1)
	{
		bus[i] = bus[i + 1];
		i++;
	}
	bus[length - 1] = c;
}

void	ft_print_last_bytes(int filecount, char **files, int bytes)
{
	char	bus[bytes + 1];
	char	c;
	int		fd;
	int		i;
	int		j;

	i = 2;
	ft_str_fill(bus, bytes + 1, '\0');
	while (++i < filecount)
	{
		fd = open(files[i], O_RDONLY);
		if (errno != 0)
		{
			ft_print_error(files[i++]);
			continue ;
		}
		while ((j = read(fd, &c, 1)) > 0)
			ft_shift_insert(bus, c, bytes);
		close(fd);
		if (filecount > 4)
			ft_put_tail_header(files[i]);
		ft_putstr(bus);
		if (filecount > 4 && i != filecount - 1)
			write(1, "\n", 1);
	}
}

void	ft_print_files(int filecount, char **files, int skips)
{
	char	bus[16384 + 1];
	int		fd;
	int		i;
	int		j;

	i = 3;
	while (i < filecount)
	{
		fd = open(files[i], O_RDONLY);
		if (errno != 0)
		{
			ft_print_error(files[i]);
			i++;
			continue ;
		}
		read(fd, bus, skips);
		while ((j = read(fd, bus, 16384)) > 0)
		{
			bus[j] = '\0';
			write(1, bus, ft_strlen(bus));
		}
		close(fd);
		i++;
	}
}

int		main(int argc, char **argv)
{
	int bytes;

	if (argc <= 3)
	{
		write(2, "Invalid number of arguments\n", 28);
		return (0);
	}
	if (ft_strcmp(argv[1], "-c") != 0)
	{
		write(2, "Invalid flag\n", 13);
		return (0);
	}
	bytes = ft_atoi(argv[2]);
	bytes = bytes < 0 ? -bytes : bytes;
	if (argv[2][0] == '+')
		ft_print_files(argc, argv, bytes);
	else
		ft_print_last_bytes(argc, argv, bytes);
	return (0);
}
