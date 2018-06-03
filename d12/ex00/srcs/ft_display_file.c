/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 08:33:47 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/16 14:29:28 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	char	buf[4096 + 1];
	int		end;
	int		fd;

	if (argc != 2)
	{
		if (argc == 1)
		{
			write(2, "File name missing.\n", 19);
			return (0);
		}
		write(2, "Too many arguments.\n", 20);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (0);
	while ((end = read(fd, buf, 4096)))
	{
		buf[end] = '\0';
		write(1, buf, end);
	}
	close(fd);
}
