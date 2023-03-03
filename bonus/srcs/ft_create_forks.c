/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_forks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 20:30:43 by jperez            #+#    #+#             */
/*   Updated: 2023/03/03 20:50:38 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philosophers_bonus.h"

void	ft_end_forks(t_mem *mem, int num)
{
	int	i;

	i = -1;
	sem_wait(mem->kill_sem);
	while (++i < num)
		kill(mem->pid[i], SIGKILL);
	mem->dead = DEAD;
	i = -1;
	while (++i < mem->num * mem->times_eat)
		sem_post(mem->meals_sem);
	i = -1;
	while (++i < mem->num)
		waitpid(mem->pid[i], NULL, 0);
}

void	ft_meals_thread(t_mem *mem)
{
	pthread_t	check_meals;

	if (mem->times_eat != -1)
	{
		pthread_create(&check_meals, NULL, &ft_check_meals, mem);
		pthread_detach(check_meals);
	}
}

void	ft_create_forks(t_mem *mem)
{
	int	i;

	i = -1;
	//mem->start = get_time();
	while (++i < mem->num)
	{
		mem->pid[i] = fork();
		if (mem->pid[i] == 0)
		{
			mem->philo->id = i;
			ft_philo_actions(mem);
			exit(-1);
		}
	}
	ft_meals_thread(mem);
	mem->start = get_time();
	sem_post(mem->start_sem);
	ft_end_forks(mem, mem->num);
}
