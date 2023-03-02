/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_param.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 21:17:22 by jperez            #+#    #+#             */
/*   Updated: 2023/03/02 20:31:28 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philosophers.h"

int	ft_check_argv(char **argv)
{
	int	i;
	int	j;

	i = -1;
	while (argv[++i])
	{
		if (!ft_strlen(argv[i]))
			return (1);
		j = -1;
		while (argv[i][++j])
			if (!('0' <= argv[i][j] && argv[i][j] <= '9'))
				return (1);
	}
	return (0);
}

t_philo_status *ft_initialize_philos_status(int num)
{
	int	i;
	t_philo_status	*philos_status;

	philos_status = (t_philo_status *)malloc(sizeof(t_philo_status) * (num + 1));
	if (!philos_status)
		return (NULL);
	i = -1;
	while (++i < num)
		philos_status[i] = thinking;
	return (philos_status);
}

int	ft_save_param(char **argv, int argc, t_mem *mem)
{
	if (ft_check_argv(argv))
		return (1);
	mem->start_cont = 1;
	mem->num = ft_atoi(argv[0]);
	mem->die = ft_atoi(argv[1]) * 1000;
	mem->eat = ft_atoi(argv[2]) * 1000;
	mem->sleep = ft_atoi(argv[3]) * 1000;
	if (argc == 6)
		mem->times_to_eat = ft_atoi(argv[4]);
	else
		mem->times_to_eat = -1;
	mem->status = creating;
	mem->philos_finished = 0;
	mem->philos_status = ft_initialize_philos_status(mem->num);
	return (0);
}
