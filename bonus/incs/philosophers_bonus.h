/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 19:31:50 by jperez            #+#    #+#             */
/*   Updated: 2023/03/03 19:22:33 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H

# define PHILOSOPHERS_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <time.h>
# include <unistd.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>

# define PHILO_SEM_NAME	"philo_sem"
# define PRINT_SEM_NAME	"print_sem"
# define KILL_SEM_NAME	"kill_sem"
# define DEAD_SEM_NAME	"dead_sem"
# define MEALS_SEM_NAME	"meals_sem"
# define START_SEM_NAME	"start_sem"
# define ALIVE		0
# define DEAD		1
# define EATING		2

typedef struct s_philo	t_philo;

typedef struct s_mem
{
	int				num;
	int				times_eat;
	int				philo_ended;
	suseconds_t		die;
	suseconds_t		eat;
	suseconds_t		sleep;
	t_philo			*philo;
	long			start;
	int				dead;
	int				max_eat;
	int				*pid;
	sem_t			*philo_sem;
	sem_t			*print_sem;
	sem_t			*kill_sem;
	sem_t			*dead_sem;
	sem_t			*meals_sem;
	sem_t			*start_sem;
}	t_mem;

typedef struct s_philo
{
	int			id;
	int			dead;
	int			times_eat;
	long		start;
	int			status;
	pthread_t	cheff;
	
}	t_philo;

/* ---------- MESSAGE -----------*/

# define FORK	"has taken a fork"
# define EAT	"is eating"
# define SLEEP	"is sleeping"
# define THINK	"is thinking"
# define DIE	"died"

/* ---------- COLORS -----------*/
# define GREEN	"\033[0;32m"
# define BLUE	"\033[0;36m"
# define RED	"\033[0;31m"
# define BLUE2	"\033[0;34m"
# define WHITE	"\033[0;37m"

/*==============================================*/
/*					FUNCTIONS					*/
/*==============================================*/

/* ----------- AUX --------------*/
int	ft_atoi(const char *str);
int	ft_strlen(char *str);

/* ----------- SAVE-PARAM --------------*/
int	ft_save_param(char **argv, int argc, t_mem *mem);

/* ----------- SAVE-PARAM --------------*/
int	ft_initialize_philo(t_mem *mem);

/* ----------- GENERAL_FREE --------------*/
void	ft_general_free(t_mem *mem);

/* ----------- PHILO-ACTIONS --------------*/
void	ft_philo_actions(t_mem *mem);

/* ----------- MANAGE-TIME--------------*/
long	get_time(void);
void	ft_usleep(suseconds_t time);

/* ----------- CREATE-FORKSCREATE-FORKS  --------------*/
void	ft_create_forks(t_mem *mem);

/* ----------- MANAGE-SEM --------------*/
void	ft_initialize_sems(t_mem *mem);

/* ----------- MANAGE-SEM --------------*/
void	*ft_cheff(void *arg);
void	*ft_check_meals(void *arg);

/* ----------- MANAGE-SEM --------------*/
void	ft_print_msg(t_mem *mem, char *color, char *msg);

#endif
