/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_strutils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 14:16:37 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/23 11:49:53 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

extern t_bsq	*g_bsq_info;
extern t_board	*g_board;

void			ft_putchar(char c)
{
	write(1, &c, 1);
}

int				ft_check_char_validity(char c)
{
	if (c == g_bsq_info->empty || c == g_bsq_info->obstacle ||
			c == g_bsq_info->full)
		return (1);
	return (0);
}

void			ft_file_skip_first_line(int fd)
{
	char c;

	while (read(fd, &c, 1) == 1 && c != '\n')
		;
}

int				ft_first_line_len(char *str)
{
	int i;

	i = 0;
	while (*str && *str != '\n')
	{
		str++;
		i++;
	}
	return (i);
}

int				ft_free_on_fail(int max_line)
{
	int i;

	i = 0;
	while (i < max_line)
	{
		if (g_board->data[i] == NULL && g_board->solving[i] == NULL)
			break ;
		if (g_board->data[i] != NULL)
			free(g_board->data[i]);
		if (g_board->solving[i] != NULL)
			free(g_board->solving[i]);
		i++;
	}
	return (0);
}
