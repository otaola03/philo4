/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_forks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 20:30:43 by jperez            #+#    #+#             */
/*   Updated: 2023/02/28 18:45:33 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philosophers_bonus.h"

void	ft_create_forks(t_mem *mem)
{
	int	i;
	pthread_t	check_meals;

	i = -1;
	mem->start = get_time();
	while (++i < mem->num)
	{
		mem->pid[i] = fork();
		if (mem->pid[i] == 0)
		{
			mem->philo->id = i;
			ft_philo_actions(mem);
			return ;
		}
	}
	if (mem->times_eat != -1)
	{
		pthread_create(&check_meals, NULL, &ft_check_meals, mem);
		pthread_detach(check_meals);
	}
	sem_post(mem->start_sem);
	sem_wait(mem->kill_sem);
	i = -1;
	while (++i < mem->num)
		kill(mem->pid[i], SIGKILL);
	i = -1;
	while (++i < mem->num)
		waitpid(mem->pid[i], NULL, 0);
}
