/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_actions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 21:15:40 by jperez            #+#    #+#             */
/*   Updated: 2023/03/04 14:20:45 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philosophers.h"

void	ft_take_forks(t_philo *philo, int n, int id)
{
	ft_lock_mutex(philo->fork1);
	ft_print_msg(philo, WHITE, "has taken a fork", get_time());
	ft_lock_mutex(philo->fork2);
	ft_print_msg(philo, WHITE, "has taken a fork", get_time());
	philo->status = eating;
}

int	ft_eat(t_philo *philo)
{
	ft_take_forks(philo, philo->mem->num, philo->id);
	ft_print_msg(philo, GREEN, "is eating", get_time());
	philo->start = get_time();
	ft_usleep2(philo->mem->eat);
	ft_lock_mutex(&philo->mem->gap_mtx);
	philo->mem->start_time += get_time() % 10;
	ft_unlock_mutex(&philo->mem->gap_mtx);
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
		{
			ft_lock_mutex(&philo->mem->cont_mtx);
			philo->mem->start_cont += philo->times_eat;
			ft_unlock_mutex(&philo->mem->cont_mtx);
			break ;
		}
		ft_print_msg(philo, PURPLE, "is sleeping", get_time());
		ft_usleep2(philo->mem->sleep);
		ft_lock_mutex(&philo->mem->gap_mtx);
		philo->mem->start_time += get_time() % 10;
		ft_unlock_mutex(&philo->mem->gap_mtx);
		ft_print_msg(philo, CYAN, "is thiking", get_time());
	}
}

void	*ft_philo_actions(void *arg)
{
	t_philo	*philo;

	philo = arg;
	philo->mem->status = alive;
	philo->start = get_time();
	if (philo->id % 2 == 0)
		ft_usleep2(philo->mem->sleep / 1000);
	ft_philo_loop(philo);
	philo->mem->philos_finished++;
	return (0);
}
