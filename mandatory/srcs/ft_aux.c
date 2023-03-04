/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 21:01:25 by jperez            #+#    #+#             */
/*   Updated: 2023/03/04 14:14:24 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philosophers.h"
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

void	ft_lock_mutex(pthread_mutex_t *mutex)
{
	if (pthread_mutex_lock(mutex))
		printf("MALLL\n");
}

void	ft_unlock_mutex(pthread_mutex_t *mutex)
{
	if (pthread_mutex_unlock(mutex))
		printf("MALLL\n");
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
