/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 11:09:13 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/16 14:28:12 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

void	ft_print_error(char *file)
{
	write(2, "cat: ", 5);
	write(2, file, ft_strlen(file));
	if (errno == 21)
		write(2, ": Is a directory\n", 17);
	else if (errno == 13)
		write(2, ": Permission denied\n", 20);
	else if (errno == 2)
		write(2, ": No such file or directory\n", 28);
}

void	ft_print_files(int filecount, char **files)
{
	char	bus[16384 + 1];
	int		fd;
	int		i;
	int		j;

	i = 1;
	while (i < filecount)
	{
		fd = open(files[i], O_RDWR);
		if (errno != 0)
		{
			ft_print_error(files[i]);
			i++;
			continue ;
		}
		while ((j = read(fd, bus, 16384)) > 0)
		{
			bus[j] = '\0';
			write(1, bus, ft_strlen(bus));
		}
		close(fd);
		i++;
	}
}

void	ft_print_input(void)
{
	int		i;
	char	c;

	while ((i = read(0, &c, 1) > 0))
		write(1, &c, 1);
}

int		main(int argc, char **argv)
{
	if (argc == 1)
		ft_print_input();
	else
		ft_print_files(argc, argv);
	return (0);
}
