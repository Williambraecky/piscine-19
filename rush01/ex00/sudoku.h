/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouvroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 10:51:22 by nrouvroy          #+#    #+#             */
/*   Updated: 2018/05/13 19:43:32 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUDOKU_H
# define SUDOKU_H
# include <unistd.h>
# include <stdlib.h>

# define TRUE 1
# define FALSE 0

# define ROW 1
# define COLUMN 0

# define INVALID_CHAR -1
# define INVALID_ARGLEN -2
# define INVALID_GRID -3
# define INVALID_ARGC -4
# define INVALID_SUDOKU -5

struct			s_udoku
{
	int fancy;
	int grid[9][9];
	int ordergrid[9][9];
};

typedef struct	s_pos
{
	int x;
	int y;
}				t_pos;

void			ft_reset(int x, int y);
void			ft_fill_order_grid(void);
void			ft_place(int x, int y, int i);
int				ft_is_sudoku_valid(void);
int				ft_check_grid(void);
int				ft_check_column(int x, int i);
int				ft_check_row(int y, int i);
int				ft_check_section(int x, int y, int i);
int				ft_try_placement(int x, int y, int i);
int				ft_parse_grid(int argc, char **argv);
void			ft_print_grid(void);
#endif
