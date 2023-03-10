/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:15:48 by jperez            #+#    #+#             */
/*   Updated: 2023/03/04 13:28:49 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philosophers_bonus.h"

void	ft_putchar(char c) {
	write(1, &c, 1);
}

void	ft_putnbr(long nb) {
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

void	ft_print_msg(t_mem *mem, char *color, char *msg, long time)
{
	//long	time;

	//time = get_time();
	sem_wait(mem->print_sem);
	if (mem->dead == ALIVE)
	{
		write(1, color, 7);
		write(1, " ", 1);
		ft_putnbr((get_time() - mem->start));
		write(1, " ", 1);
		ft_putnbr(mem->philo->id + 1);
		write(1, " ", 1);
		write(1, msg, ft_strlen(msg));
		write(1, " ", 1);
		write(1, WHITE, 7);
		write(1, "\n", 1);
	}
	if (mem->dead != DEAD)
		sem_post(mem->print_sem);
}
