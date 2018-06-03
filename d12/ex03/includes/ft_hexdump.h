/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 15:13:23 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/16 17:21:45 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEXDUMP_H
# define FT_HEXDUMP_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <errno.h>

void			ft_putaddress(int addr, int index, int length);

struct			s_special_char
{
	char		c;
	char		str[3];
};

typedef struct s_special_char	t_sp_char;

int				ft_strlen(char *str);
int				ft_strcmp(char *s1, char *s2);
int				ft_atoi(char *str);
void			ft_putaddress(int addr, int index, int length);
void			ft_putspecialchar(char c);
void			ft_bad_file_descriptor(char *file);
void			ft_print_error(char *file);
int				ft_str_only_space(char *str);

#endif
