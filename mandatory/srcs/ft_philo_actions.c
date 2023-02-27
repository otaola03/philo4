/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_actions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 21:15:40 by jperez            #+#    #+#             */
/*   Updated: 2023/02/27 18:37:39 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philosophers.h"

int ft_take_forks(t_philo *philo, int n, int id)
{
	if ((philo->mem->philos_status[(id + (n - 1))  % n] != eating && philo->mem->philos_status[(id + 1) % n] != eating))
	{
		ft_lock_mutex(philo->fork1);
		ft_print_msg(philo, WHITE, "has taken a fork", get_time());
		ft_lock_mutex(philo->fork2);
		ft_print_msg(philo, WHITE, "has taken a fork", get_time());
		philo->status = eating;
		return (0);
	}
	return (1);
}

int	ft_eat(t_philo *philo)
{
	/*
	while (ft_take_forks(philo, philo->mem->num, philo->id))
		usleep(1);
		*/
		ft_lock_mutex(philo->fork1);
		ft_print_msg(philo, WHITE, "has taken a fork", get_time());
		ft_lock_mutex(philo->fork2);
		ft_print_msg(philo, WHITE, "has taken a fork", get_time());
		philo->status = eating;

	ft_print_msg(philo, GREEN, "is eating", get_time());
	philo->start = get_time();
	ft_usleep2(philo->mem->eat);
	philo->mem->start_time += get_time()%10;

	ft_unlock_mutex(philo->fork1);
	ft_unlock_mutex(philo->fork2);

	philo->times_eat++;
	philo->status = sleeping;
	return (philo->times_eat);
}

void	ft_philo_loop(t_philo *philo)
{
	while (philo->mem->status == alive)
	{
		if (ft_eat(philo) == philo->mem->times_to_eat)
			break ;
		ft_print_msg(philo, PURPLE, "is sleeping", get_time());
		ft_usleep2(philo->mem->sleep);
		philo->mem->start_time += get_time()%10;
		ft_print_msg(philo, CYAN, "is thiking", get_time());
	}
}

void	*ft_philo_actions(void *arg)
{
	t_philo *philo;

	philo = arg;
	philo->mem->status  = alive; 
	/*
	while (philo->mem->status == creating)
		usleep(1);
	*/
	/*
	if (philo->id % 2 == 0)
	{
		while (philo->mem->start_cont != philo->mem->num / 2)
			usleep(1);
	}
	else
		philo->mem->start_cont++;
		*/
	philo->start = get_time();
	if (philo->id % 2 == 0)
		ft_usleep2(philo->mem->sleep/1000);
	ft_philo_loop(philo);
	philo->mem->philos_finished++;
	return (0);
}