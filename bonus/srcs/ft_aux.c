/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 21:01:25 by jperez            #+#    #+#             */
/*   Updated: 2022/12/28 19:54:51 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philosophers_bonus.h"
#include <math.h>

int	ft_atoi(const char *str)
{
	int	num;
	int	sign;

	sign = 1;
	num = 0;
	while ((9 <= *str && *str <= 13) || (int)*str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
		num = num * 10 + (*str++ - '0');
	return (num * sign);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}
