/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 07:49:06 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/03 16:30:51 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_fill_array(int *current, int size, int start)
{
	int i;
	
	i = 0;
	while (i < size)
	{
		current[i] = i + start;
		i++;
	}
}

int		ft_should_print(int *current, int size)
{
	int i;

	i = 0;
	while (i < size - 1)
	{
		if (current[i] >= current[i + 1] || current[i + 1] + '0' > '9')
			return 0;
		i++;
	}
	return 1;
}

void	ft_print_array(int *current, int size)
{
	int i;

	i = 0;
	if (!ft_should_print(current, size))
		return;
	while (i < size)
	{
		ft_putchar(current[i] + '0');
		i++;
	}
	if (current[0] != 10 - size)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_array_increment_print(int *current, int size, int pos)
{
	int i;

	while (current[pos] < 11 - (size - pos))
	{
		if (pos != size - 1)
			ft_array_increment_print(current, size, pos + 1);
		ft_print_array(current, size);
		current[pos]++;
		if (pos != size - 1 && current[pos] < 11 - (size - pos))
		{
			i = 1;
			while (i < size)
			{
				current[pos + i] = current[pos] + i;
				i++;
			}
		}
	}

}

void	ft_print_combn(int n)
{
	int	current[n];
	int	i;

	i = n;
	ft_fill_array(current, i, 0);
	while (current[0] <= 10 - i)
	{
		ft_array_increment_print(current, i, 1);
		ft_fill_array(current, i, current[0] + 1);
	}
}

int		main()
{
	ft_print_combn(9);
	ft_putchar('\n');
}
