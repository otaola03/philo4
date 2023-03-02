/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cheff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:41:55 by jperez            #+#    #+#             */
/*   Updated: 2023/03/02 20:28:00 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philosophers_bonus.h"

int	ft_check_live(t_mem *mem)
{
	long	end;

	//end = get_time();
	usleep(1000);
	if (get_time() - mem->philo->start > mem->die)
	{
		sem_wait(mem->dead_sem);
		if (mem->dead == ALIVE)
			ft_print_msg(mem, RED, DIE);
		sem_wait(mem->print_sem);
		mem->dead = DEAD;
		return (1);
	}
	usleep(100);
	return (0);
}

void	*ft_cheff(void *arg)
{
	int	i;

	t_mem	*mem;

	mem = arg;
	while (mem->dead == ALIVE)
	{
		if (ft_check_live(mem))
			break;
	}
	sem_post(mem->kill_sem);
	return (0);
}

void	*ft_check_meals(void *arg)
{
	int		i;
	t_mem	*mem;

	mem = arg;
	i = -1;
	while (++i < mem->num * mem->times_eat)
		sem_wait(mem->meals_sem);
	if (mem->dead == DEAD)
		return (0);
	sem_wait(mem->print_sem);
	sem_post(mem->kill_sem);
	return (0);
}
