/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maanage_sem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:33:18 by jperez            #+#    #+#             */
/*   Updated: 2023/03/01 18:06:22 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philosophers_bonus.h"

void	ft_create_sem(t_mem *mem, sem_t **sem, char *name, int num)
{
	sem_unlink(name);
	*sem = sem_open(name, O_CREAT | O_EXCL, 0666, num);
	if (*sem == SEM_FAILED)
	{
		perror("");
		ft_general_free(mem);
		exit(-1);
	}
}

void	ft_initialize_sems(t_mem *mem)
{
	ft_create_sem(mem, &mem->philo_sem, PHILO_SEM_NAME, mem->num);
	ft_create_sem(mem, &mem->print_sem, PRINT_SEM_NAME, 1);
	ft_create_sem(mem, &mem->kill_sem, KILL_SEM_NAME, 0);
	ft_create_sem(mem, &mem->dead_sem, DEAD_SEM_NAME, 1);
	ft_create_sem(mem, &mem->meals_sem, MEALS_SEM_NAME, 0);
	ft_create_sem(mem, &mem->start_sem, START_SEM_NAME, 0);
}
