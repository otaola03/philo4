/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_time.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:40:28 by jperez            #+#    #+#             */
/*   Updated: 2023/03/03 17:14:34 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philosophers_bonus.h"

long	get_time(void)
{
	struct timeval	time;
	long			milliseconds;

	gettimeofday(&time, NULL);
	milliseconds = time.tv_sec * 1000;
	milliseconds += time.tv_usec / 1000;
	return (milliseconds * 1000);
}

void	ft_usleep(suseconds_t time)
{
	long	start;
	long	end;

	start = get_time();
	while (get_time() - start < time)
	{
		usleep(1000);
	}
}
