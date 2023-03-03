/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dealer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:18:49 by jperez            #+#    #+#             */
/*   Updated: 2023/03/03 20:39:32 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philosophers.h"

int	ft_check_live(t_philo *philo, long start)
{
	if (get_time() - start > philo->mem->die)
	{
		usleep(50);
		ft_print_msg(philo, RED, "is dead", get_time());
		philo->mem->status = dead;
	//	return (1);
		exit(-1);;
	}
	return (0);
}

void	*ft_cheff(void *arg)
{
	int		i;
	t_mem	*mem;

	mem = arg;
	while (mem->status == creating)
		usleep(1);
	while (mem->status == alive)
	{
		i = -1;
		while (++i < mem->num && mem->status == alive)
			if (ft_check_live(mem->philo[i], mem->philo[i]->start) \
				|| mem->start_cont != mem->times_to_eat * mem->num)
				return (0);
	}
}
