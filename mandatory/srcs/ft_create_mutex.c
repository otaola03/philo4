/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_mutex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 20:59:56 by jperez            #+#    #+#             */
/*   Updated: 2023/02/26 18:24:25 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philosophers.h"

int	ft_create_mutex(t_mem *mem, int num)
{
	int	i;

	mem->forks_mtx = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * (num + 1));
	i = -1;
	while (++i < num)
		if (pthread_mutex_init(&mem->forks_mtx[i], NULL))
			return (1);
	if (pthread_mutex_init(&mem->print_mtx, NULL))
		return (1);
	return (0);
}

void	ft_destroy_mutex(t_mem *mem, int num)
{
	int	i;

	i = -1;
	while (++i < num)
		if (pthread_mutex_destroy(&mem->forks_mtx[i]))
			return ;
	if (pthread_mutex_destroy(&mem->print_mtx))
		return ;
}
