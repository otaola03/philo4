/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_general_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 18:09:45 by jperez            #+#    #+#             */
/*   Updated: 2023/02/26 18:30:17 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philosophers.h"

void	ft_free_philo(t_philo **philo, int num)
{
	int	i;

	i = -1;
	while (++i < num)
		free(philo[i]);
	free(philo);
}

void	ft_general_free(t_mem *mem)
{
	ft_destroy_mutex(mem, mem->num);
	free(mem->forks_mtx);
	free(mem->th);
	ft_free_philo(mem->philo, mem->num);
	free(mem);
}
