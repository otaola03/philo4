/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_param.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 21:17:22 by jperez            #+#    #+#             */
/*   Updated: 2023/03/03 19:23:31 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philosophers_bonus.h"

int	ft_check_argv(char **argv)
{
	int	i;
	int	j;

	i = -1;
	while (argv[++i])
	{
		j = -1;
		if (!ft_strlen(argv[i]))
			return (1);
		while (argv[i][++j])
			if (!('0' <= argv[i][j] && argv[i][j] <= '9'))
				return (1);
	}
	return (0);
}

int	ft_save_param(char **argv, int argc, t_mem *mem)
{
	if (ft_check_argv(argv))
	{
		free(mem);
		return (1);
	}
	mem->num = ft_atoi(argv[0]);
	mem->die = ft_atoi(argv[1]) * 1000;
	mem->eat = ft_atoi(argv[2]) * 1000;
	mem->sleep = ft_atoi(argv[3]) * 1000;
	if (argc == 6)
	{
		mem->times_eat = ft_atoi(argv[4]);
		mem->max_eat = mem->num * mem->times_eat;
	}
	else
		mem->times_eat = -1;
	mem->dead = ALIVE;
	mem->philo_ended = 0;
	mem->pid = (int *)malloc(sizeof(int) * mem->num);
	return (0);
}
