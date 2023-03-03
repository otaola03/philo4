/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:21:27 by jperez            #+#    #+#             */
/*   Updated: 2023/03/03 21:26:51 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philosophers.h"

void	ft_putchar(char c) {
	write(1, &c, 1);
}

void	ft_putnbr(int nb) {
	if (nb < 0) {
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10) {
		ft_putnbr(nb / 10);
		nb = nb % 10;
	}
	if (nb < 10) ft_putchar(nb + 48);
}

void	ft_print_msg(t_philo *philo, char *color, char *msg, long end)
{
	if (philo->mem->start_cont == philo->mem->times_to_eat * philo->mem->num)
		return ;
	ft_lock_mutex(&philo->mem->print_mtx);
	if (philo->mem->status != dead)
	{
		write(1, color, 7);
		write(1, " ", 1);
		ft_putnbr((end - philo->mem->start_time) / 1000);
		write(1, " ", 1);
		ft_putnbr(philo->id + 1);
		write(1, " ", 1);
		write(1, msg, ft_strlen(msg));
		write(1, " ", 1);
		write(1, WHITE, 7);
		write(1, "\n", 1);
	}
	ft_unlock_mutex(&philo->mem->print_mtx);
}
