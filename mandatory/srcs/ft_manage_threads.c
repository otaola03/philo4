/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_threads.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:23:48 by jperez            #+#    #+#             */
/*   Updated: 2023/03/05 18:28:31 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philosophers.h"

int	ft_create_threads(t_mem *mem, int num)
{
	int	i;

	mem->start_time = get_time();
	i = -1;
	while (++i < num)
	{
		if (pthread_create(&mem->th[i], NULL, &ft_philo_actions, mem->philo[i]))
			return (1);
	}
	mem->status = alive;
	if (pthread_create(&mem->cheff, NULL, &ft_cheff, mem))
		return (1);
	return (0);
}

int	ft_join_threads(t_mem *mem, int num)
{
	int	i;

	i = -1;
	while (++i < num)
	{
		if (pthread_join(mem->th[i], NULL))
			return (1);
	}
	if (pthread_join(mem->cheff, NULL))
		return (1);
	return (0);
}

int	ft_start_threads(t_mem *mem, int num)
{
	if (num == 1)
	{
		printf("%d 1 has taken a fork\n", 0);
		ft_usleep2(mem->sleep);
		printf("%s%ld 1 died%s\n", RED, mem->dead / 1000, WHITE);
		return (1);
	}
	mem->th = (pthread_t *)malloc(sizeof(pthread_t) * num);
	if (!mem->th)
		return (1);
	ft_create_threads(mem, num);
	ft_join_threads(mem, num);
	return (0);
}
