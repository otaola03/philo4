/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialice_philo.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 20:35:24 by jperez            #+#    #+#             */
/*   Updated: 2023/02/26 18:44:31 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philosophers.h"

int	ft_initialize_philo(t_mem *mem, int n)
{
	int	i;

	mem->philo = (t_philo **)malloc(sizeof(t_philo *) * mem->num + 1);
	if (!mem->philo)
		return (1);
	i = -1;
	while (++i < mem->num)
	{
		mem->philo[i] = (t_philo *)malloc(sizeof(t_philo));
		if (!mem->philo[i])
			return (1);
		mem->philo[i]->id = i;
		mem->philo[i]->fork1 = &mem->forks_mtx[(i + 1) % n];
		mem->philo[i]->fork2 = &mem->forks_mtx[i];
		mem->philo[i]->status = thinking;
		mem->philo[i]->times_eat = 0;
		mem->philo[i]->start = 0;
		mem->philo[i]->mem = mem;
	}
	return (0);
}
