/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_stdinput.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouvroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 15:05:53 by nrouvroy          #+#    #+#             */
/*   Updated: 2018/05/23 18:23:00 by nrouvroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

extern t_bsq	*g_bsq_info;
extern t_board	*g_board;

void	ft_bsq_stdinput(void)
{
	int		w;
	int		i_oc[2];
	char	c;
	t_list	**list;
	t_list	*start;

	start = NULL;
	list = &start;
	c = 0;
	w = ft_init_list(list, NULL, c, -1);
	g_bsq_info->width = w;
	g_board->solving[0] = (int *)malloc(sizeof(int) * w);
	if (g_board->solving[0] == NULL)
		ft_exit();
	i_oc[0] = -1;
	i_oc[1] = 0;
	while (++i_oc[0] < g_bsq_info->width)
	{
		i_oc[1] += (g_board->data[0][i_oc[0]] == g_bsq_info->obstacle);
		g_board->solving[0][i_oc[0]] = i_oc[1];
	}
	ft_stdin_parse_lines();
	ft_bsq_resolve();
	ft_print_bsq();
}

int		ft_init_list(t_list **list, t_list *start, char c, int w)
{
	if ((g_bsq_info = ft_create_bsq_info()) == NULL)
		ft_exit();
	while (read(0, &c, 1) > 0 && c != '\n' && c != '\0')
		ft_listpushback(list, c);
	if (ft_listlen(*list) >= 14 || ft_listlen(*list) <= 4)
		ft_exit();
	g_bsq_info->full = ft_listpop(list);
	g_bsq_info->obstacle = ft_listpop(list);
	g_bsq_info->empty = ft_listpop(list);
	if (g_bsq_info->full == g_bsq_info->obstacle || g_bsq_info->full ==
			g_bsq_info->empty || g_bsq_info->obstacle == g_bsq_info->empty)
		ft_exit();
	g_bsq_info->height = ft_listint(list);
	ft_init_board();
	*list = start;
	while (++w >= 0 && read(0, &c, 1))
	{
		ft_listpushback(list, c);
		if (c == '\n' || c == '\0')
			break ;
	}
	g_board->data[0] = ft_listgetbuf(list);
	return (w);
}

void	ft_malloc_line(int line)
{
	if (line >= g_bsq_info->height)
		return ;
	g_board->data[line] = (char *)malloc(sizeof(char) * g_bsq_info->width + 1);
	g_board->solving[line] = (int *)malloc(sizeof(int) * g_bsq_info->width);
	if (g_board->data[line] == NULL || g_board->solving[line] == NULL)
		ft_exit();
}

void	ft_process_buffer(char *buffer, int *line, int *col, int *o_c)
{
	int i;

	i = -1;
	while (buffer[++i] != '\0' && *line < g_bsq_info->height)
	{
		if (buffer[i] == '\n')
		{
			if (*col != g_bsq_info->width)
				ft_exit();
			g_board->data[*line][*col] = '\n';
			*col = 0;
			*line = *line + 1;
			ft_malloc_line(*line);
			*o_c = 0;
			continue ;
		}
		if (!ft_check_char_validity(buffer[i]))
			ft_exit();
		g_board->data[*line][*col] = buffer[i];
		*o_c += buffer[i] == g_bsq_info->obstacle;
		g_board->solving[*line][*col] =
			(*o_c + g_board->solving[*line - 1][*col]);
		*col = *col + 1;
	}
}

void	ft_stdin_parse_lines(void)
{
	char	buffer[255 + 1];
	int		j;
	int		line;
	int		col;
	int		o_c;

	line = 1;
	col = 0;
	o_c = 0;
	ft_malloc_line(line);
	while ((j = read(0, buffer, 255)) > 0 && line < g_bsq_info->height)
	{
		buffer[j] = '\0';
		ft_process_buffer(buffer, &line, &col, &o_c);
		if (line == g_bsq_info->height)
			break ;
	}
}
