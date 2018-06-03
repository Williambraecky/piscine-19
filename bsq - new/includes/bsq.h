/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 14:00:01 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/23 18:21:08 by nrouvroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/uio.h>
# include <sys/types.h>
# include <fcntl.h>

# define PARSE_OK 1
# define NO_MEMORY -1
# define INVALID_INFO -2
# define INVALID_FILE -3
# define INVALID_MAP -4

typedef struct	s_solution
{
	int			x;
	int			y;
	int			size;
}				t_solution;

typedef struct	s_list
{
	struct s_list	*next;
	char			data;
}				t_list;

typedef struct	s_board
{
	char		**data;
	int			**solving;
}				t_board;

typedef struct	s_bsq
{
	int			height;
	int			width;
	char		empty;
	char		obstacle;
	char		full;
	t_solution  *solution;
}				t_bsq;

void			ft_stdin_parse_lines(void);
t_bsq			*ft_create_bsq_info(void);
void			ft_print_bsq(void);
int				ft_check_char_validity(char c);
void			ft_bsq_resolve(void);
void			ft_putchar(char c);
t_solution		*ft_empty_solution(void);
int				ft_test_square(int **table, int i, int j, int size);
void			ft_replace_board_with_solution(t_solution *solution);
int				ft_first_line_len(char *str);
void			ft_file_skip_first_line(int fd);
int				ft_file_get_line_len(int fd, char *buffer, int max);
int				ft_init_board(void);
int				ft_free(void *data);
void			ft_free_struct(void);
int				ft_parse_info(char *buffer);
int				ft_parse_bsq(char *file);
int				ft_parse_line(int fd, int line);
int				ft_parse_lines(int fd, char *buffer, char *file);
void			ft_exit();
void			ft_listpushback(t_list **list, char c);
char			ft_listpop(t_list **blist);
int				ft_listint(t_list **blist);
int				ft_listlen(t_list *blist);
char			*ft_listgetbuf(t_list **list);
void			ft_bsq_stdinput(void);
int				ft_free_on_fail(int max_line);
int				ft_init_list(t_list **list, t_list *start, char c, int w);
int				min(int a, int b, int c);

#endif
