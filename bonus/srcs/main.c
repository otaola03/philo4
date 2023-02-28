/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:53:31 by jperez            #+#    #+#             */
/*   Updated: 2023/01/07 19:05:47 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philosophers_bonus.h"

int	main(int argc, char **argv)
{
	t_mem	*mem;

	if (!(5 <= argc && argc <= 6))
		return (1);
	mem = (t_mem *)malloc(sizeof(t_mem));
	if (!mem)
		return (1);
	if (ft_save_param(++argv, argc, mem) || ft_initialize_philo(mem))
		return (1);
	ft_initialize_sems(mem);
	ft_create_forks(mem);
	ft_general_free(mem);
	return (0);
}
