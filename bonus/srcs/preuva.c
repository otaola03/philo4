
#include "../incs/philosophers_bonus.h"

void	ft_print_msg(t_mem *mem, int msg)
{
	long	end;

	end = get_time();
	if (msg == 1 && mem->dead == 0)
		printf("%ld %d %s\n\n", \
			(end - mem->start) / 1000, mem->philo->id, FORK);
	else if (msg == 3 && mem->dead == 0)
	{
		mem->philo->times_eat++;
		printf("\033[0;32m%ld %d %s\033[0m\n\n", \
			(end - mem->start) / 1000, mem->philo->id, EAT);
	}
	else if (msg == 4 && mem->dead == 0)
		printf("\033[0;36m%ld %d %s\n\n\033[0m", \
			(end - mem->start) / 1000, mem->philo->id, SLEEP);
	else if (msg == 5 && mem->dead == 0)
		printf("\033[0;36m%ld %d %s\n\n\033[0m", \
			(end - mem->start) / 1000, mem->philo->id, THINK);
}

void	ft_philo_actions(t_mem *mem)
{
	if (mem->philo->id % 2 == 0)
		usleep(1000);
	mem->philo->start = get_time();
	while (mem->dead == 0)
	{
		printf("--->sem: %d\n", sem_wait(mem->sem));
		ft_print_msg(mem, 1);

		sem_wait(mem->sem);
		ft_print_msg(mem, 1);

		ft_print_msg(mem, 3);
		mem->philo->start = get_time();
		ft_usleep2(mem->eat);

		sem_post(mem->sem);
		sem_post(mem->sem);

		/*
		if (mem->philo->times_eat == mem->times_eat)
			break ;
			*/
		ft_print_msg(mem, 4);
		ft_usleep2(mem->sleep);
		ft_print_msg(mem, 5);
	}
	mem->philo_ended++;
//	exit(1);
}
