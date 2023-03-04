/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers2.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 20:53:08 by jperez            #+#    #+#             */
/*   Updated: 2023/03/04 14:25:16 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H

# define PHILOSOPHERS_H

# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <time.h>
# include <unistd.h>
# include <pthread.h>

# define GREEN 		"\033[0;32m"
# define PURPLE		"\033[0;35m"
# define CYAN		"\033[0;36m"
# define RED		"\033[0;31m"
# define WHITE		"\033[0;37m"

typedef enum e_philo_status {
	thinking,
	eating,
	sleeping
}	t_philo_status;

typedef enum e_mem_status {
	creating,
	alive,
	dead,
	block
}	t_mem_status;

typedef struct s_philo	t_philo;

typedef struct s_mem
{
	int				num;
	int				times_to_eat;
	int				philos_finished;
	long			die;
	long			eat;
	long			sleep;
	t_philo			**philo;
	pthread_t		*th;
	pthread_t		cheff;
	pthread_mutex_t	*forks_mtx;
	pthread_mutex_t	print_mtx;
	pthread_mutex_t	cont_mtx;
	pthread_mutex_t	gap_mtx;
	long			start_time;
	t_mem_status	status;
	t_philo_status	*philos_status;
	int				start_cont;
}	t_mem;

typedef struct s_philo
{
	int				id;
	pthread_mutex_t	*fork1;
	pthread_mutex_t	*fork2;
	t_philo_status	status;
	int				times_eat;
	long			start;
	t_mem			*mem;
}	t_philo;

/*-------------- AUX -------------*/
int		ft_atoi(const char *str);
void	ft_usleep(suseconds_t time);
void	ft_lock_mutex(pthread_mutex_t *mutex);
void	ft_unlock_mutex(pthread_mutex_t *mutex);
int		ft_strlen(char *str);

/*-------------- CREATE-MUTEX -------------*/
int		ft_create_mutex(t_mem *mem, int num);
void	ft_destroy_mutex(t_mem *mem, int num);

/*-------------- SAVE-PARAM -------------*/
int		ft_check_argv(char **argv);
int		ft_save_param(char **argv, int argc, t_mem *mem);

/*-------------- PHILO-ACTIONS -------------*/
int		ft_initialize_philo(t_mem *mem, int n);
void	*ft_philo_actions(void *arg);

/*-------------- MANAGE-THREADS -------------*/
int		ft_start_threads(t_mem *mem, int num);

/*-------------- MANAGE-TIME -------------*/
long	get_time(void);
void	ft_usleep2(suseconds_t time);

/*-------------- PHILO-ACTIONS -------------*/
int		ft_check_live(t_philo *philo, long start);

/*-------------- DEALER -------------*/
void	*ft_cheff(void *arg);

/*-------------- GENERAL-FREE -------------*/
void	ft_general_free(t_mem *mem);

/*-------------- PRINT-MSG -------------*/
void	ft_print_msg(t_philo *philo, char *color, char *msg, long end);

#endif
