/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_actions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 21:15:40 by jperez            #+#    #+#             */
/*   Updated: 2023/02/28 18:52:29 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philosophers_bonus.h"

int	ft_eat(t_mem *mem)
{
	mem->philo->status = EATING;
	sem_wait(mem->philo_sem);
	ft_print_msg(mem, WHITE, FORK, get_time());
	sem_wait(mem->philo_sem);
	ft_print_msg(mem, WHITE, FORK, get_time());
	ft_print_msg(mem, GREEN, EAT, get_time());
	mem->philo->start = get_time();
	mem->start += get_time()%10;
	ft_usleep(mem->eat);
	sem_post(mem->philo_sem);
	sem_post(mem->philo_sem);
	sem_post(mem->meals_sem);
	mem->philo->times_eat++;
	return (mem->philo->times_eat);
}

void	ft_philo_actions(t_mem *mem)
{
	sem_wait(mem->start_sem);
	sem_post(mem->start_sem);
	mem->start = get_time();
	mem->philo->start = get_time();
	if (mem->philo->id %2 != 0)
		usleep(mem->sleep / 1000);
	pthread_create(&mem->philo->cheff, NULL, &ft_cheff, mem);
	while (mem->dead == ALIVE)
	{
		if (ft_eat(mem) == mem->times_eat)
			break ;
		mem->philo->status = ALIVE;
		ft_print_msg(mem, BLUE, SLEEP, get_time());
		ft_usleep(mem->sleep);
		mem->start += get_time()%10;
		ft_print_msg(mem, BLUE2, THINK, get_time());
	}
	pthread_join(mem->philo->cheff, NULL);
}
