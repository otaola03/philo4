/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:53:31 by jperez            #+#    #+#             */
/*   Updated: 2023/03/05 12:52:42 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philosophers.h"

int	main(int argc, char **argv)
{
	t_mem	*mem;

	if (!(5 <= argc && argc <= 6))
		return (1);
	mem = (t_mem *)malloc(sizeof(t_mem));
	if (!mem)
		return (1);
	if (ft_save_param(++argv, argc, mem))
	{
		free(mem);
		return (1);
	}
	if (ft_create_mutex(mem, mem->num) || ft_initialize_philo(mem, mem->num) || \
		ft_start_threads(mem, mem->num))
	{
		ft_pree_free(mem);
		return (1);
	}
	ft_general_free(mem);
	return (0);
}
