/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 09:20:07 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/14 10:27:35 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOP_H
# define DOOP_H

# include <unistd.h>

void	ft_putstr(char *str);
int		ft_is_numeric(char *str);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
int		ft_strlen(char *str);
int		ft_str_equals(char *s1, char *s2);
void	ft_add(int i, int j);
void	ft_remove(int i, int j);
void	ft_multiply(int i, int j);
void	ft_divide(int i, int j);
void	ft_modulo(int i, int j);
int		ft_atoi(char *str);

#endif
