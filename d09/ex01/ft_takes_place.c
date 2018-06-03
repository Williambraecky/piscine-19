/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takes_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 18:31:29 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/10 19:47:15 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_convert_hour(int hour)
{
	hour = hour % 24;
	if (hour == 0)
		return (12);
	else if (hour < 12)
		return (hour);
	else if (hour == 12)
		return (hour);
	return (hour % 12);
}

char	*ft_str_for_hour(int hour)
{
	if (hour % 24 < 12)
		return ("A.M.");
	return ("P.M.");
}

void	ft_takes_place(int hour)
{
	printf("THE FOLLOWING TAKES PLACE BETWEEN %d.00 %s AND %d.00 %s\n",
			ft_convert_hour(hour),
			ft_str_for_hour(hour),
			ft_convert_hour(hour + 1),
			ft_str_for_hour(hour + 1));
}
