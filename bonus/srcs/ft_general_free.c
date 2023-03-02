/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_general_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 18:09:45 by jperez            #+#    #+#             */
/*   Updated: 2023/03/01 18:05:21 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philosophers_bonus.h"

void	ft_close_sems(t_mem *mem)
{
	unlink(PHILO_SEM_NAME);
	sem_close(mem->philo_sem);
	unlink(PRINT_SEM_NAME);
	sem_close(mem->print_sem);
	unlink(KILL_SEM_NAME);
	sem_close(mem->kill_sem);
	unlink(DEAD_SEM_NAME);
	sem_close(mem->dead_sem);
	unlink(MEALS_SEM_NAME);
	sem_close(mem->meals_sem);
	unlink(START_SEM_NAME);
	sem_close(mem->start_sem);
}

void	ft_general_free(t_mem *mem)
{
	ft_close_sems(mem);
	free(mem->philo);
	free(mem->pid);
	free(mem);
}
