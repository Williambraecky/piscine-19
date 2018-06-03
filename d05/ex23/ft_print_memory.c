/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 19:43:06 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/08 21:46:09 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_puthex(char c, char *hexbase)
{
	ft_putchar(hexbase[c / 16]);
	ft_putchar(hexbase[c % 16]);
}

void	ft_putaddress(int addr, char *base, int index, int length)
{
	if (index == length)
		return ;
	ft_putaddress(addr / 16, base, index + 1, length);
	ft_putchar(base[addr % 16]);
}

void	ft_put_hexa(void *addr, int start, char *base, unsigned int size)
{
	unsigned	int	i;
	char			j;
	unsigned	int	k;

	i = start;
	k = start;
	while (i < (unsigned int)start + 16)
	{
		if (i % 2 == 0 && i != (unsigned int)start)
			ft_putchar(' ');
		if (i >= size)
		{
			ft_putchar(' ');
			ft_putchar(' ');
		}
		else
		{
			j = *((char *)addr + i);
			ft_puthex(j, base);
		}
		k++;
		i++;
	}
	ft_putchar(' ');
	ft_putchar(' ');
}

void	ft_put_str(void *addr, unsigned int start)
{
	unsigned	int	i;
	char			j;

	i = start;
	while (i < start + 16)
	{
		j = *((char *)addr + i);
		if (j <= 31)
			ft_putchar('.');
		else
			ft_putchar(j);
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	char			base[16];
	unsigned	int	j;

	j = 0;
	while (j < 16)
	{
		if (j < 10)
			base[j] = j + '0';
		else
			base[j] = j + 87;
		j++;
	}
	j = 0;
	while (j < size)
	{
		ft_putaddress(j, base, 0, 8);
		ft_putchar(':');
		ft_putchar(' ');
		ft_put_hexa(addr, j, base, size);
		ft_put_str(addr, j);
		ft_putchar('\n');
		j += 16;
	}
	return (addr);
}
