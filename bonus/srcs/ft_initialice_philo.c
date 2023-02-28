/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialice_philo.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 20:35:24 by jperez            #+#    #+#             */
/*   Updated: 2023/01/16 14:24:10 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philosophers_bonus.h"

int	ft_initialize_philo(t_mem *mem)
{
	mem->philo = (t_philo *)malloc(sizeof(t_philo));
	if (!mem->philo)
	{
		ft_general_free(mem);
		return (1);
	}
	mem->philo->id = 0;;
	mem->philo->dead = ALIVE;
	mem->philo->times_eat = 0;
	mem->philo->start = 0;
	mem->philo->status = ALIVE;
	return (0);
}
