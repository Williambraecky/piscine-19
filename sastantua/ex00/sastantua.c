/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 09:34:03 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/06 22:33:31 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		ft_getsastantuawidth(int size)
{
	int height;
	int terracewidth;

	if (size <= 0)
		return 0;
	if (size == 1)
		return (4);
	height = size + 3;
	terracewidth = size / 2;
	return (ft_getsastantuawidth(size - 1) + height + terracewidth);
}

char	ft_getchar(int size, int width, int row, int column)
{
	int doorwidth;
	int floorwidth;
	int doorheight;
	int sizewidth;
	int sizeheight;

	doorwidth = size % 2 + size / 2;
	doorheight = 1 + (size - 1) % 2;
	sizeheight = size + 1;
	sizewidth = ft_getsastantuawidth(size) - 1;
	floorwidth = sizewidth - (sizeheight - row);
	if (width >= floorwidth && column < width - floorwidth)
		return (' ');
	if (column == width - floorwidth)
		return ('/');
	if (row > 1 && row > doorheight && column > width - doorwidth)
		return ('|');
	return ('*');
}

char	ft_checkdoor(char c, int door)
{
	if (!door && (c == '|' || c == '$'))
		return ('*');
	return (c);
}

void	ft_print_sastantua(int size, int width, int door)
{
	int		i;
	int		j;
	char	c;

	if (size > 0)
		ft_print_sastantua(size - 1, width, 0);
	j = -1;
	while (size != 0 && ++j < size + 2)
	{
		i = 1;
		while (i < width)
			ft_putchar(ft_checkdoor(ft_getchar(size, width, j, i++), door));
		while (i > -1)
		{
			c = ft_checkdoor(ft_getchar(size, width, j, i--), door);
			if (c == '/')
				c = '\\';
			if (c == '|' && size >= 5 && j == size - (size % 2 + size / 2) / 2)
				if (i == (width - (size % 2 + size / 2) + 1))
					c = '$';
			if (c != ' ')
				ft_putchar(c);
		}
		ft_putchar('\n');
	}
}

void	sastantua(int size)
{
	ft_print_sastantua(size, ft_getsastantuawidth(size), 1);
}
