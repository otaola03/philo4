/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_actions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 21:15:40 by jperez            #+#    #+#             */
/*   Updated: 2023/03/03 20:43:24 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philosophers_bonus.h"

void	ft_take_forks(t_mem *mem)
{
	sem_wait(mem->philo_sem);
	ft_print_msg(mem, WHITE, FORK);
	sem_wait(mem->philo_sem);
	ft_print_msg(mem, WHITE, FORK);
}

int	ft_eat(t_mem *mem)
{
	ft_take_forks(mem);
	ft_print_msg(mem, GREEN, EAT);
	mem->philo->start = get_time();
	//mem->start += get_time() % 10;
	ft_usleep(mem->eat);
	sem_post(mem->philo_sem);
	sem_post(mem->philo_sem);
	sem_post(mem->meals_sem);
	mem->philo->times_eat++;
	return (mem->philo->times_eat);
}

void	ft_philo_loop(t_mem *mem)
{
	while (mem->dead == ALIVE)
	{
		if (ft_eat(mem) == mem->times_eat)
			break ;
		ft_print_msg(mem, BLUE, SLEEP);
		ft_usleep(mem->sleep);
		//mem->start += get_time() % 10;
		ft_print_msg(mem, BLUE2, THINK);
	}
}

void	ft_philo_actions(t_mem *mem)
{
	sem_wait(mem->start_sem);
	sem_post(mem->start_sem);
	mem->start = get_time();
	mem->philo->start = get_time();
	if (mem->philo->id %2 != 0)
	{
		usleep(500);
		usleep(500);
		usleep(500);
	}
	pthread_create(&mem->philo->cheff, NULL, &ft_cheff, mem);
	ft_philo_loop(mem);
	pthread_join(mem->philo->cheff, NULL);
	return ;
}
