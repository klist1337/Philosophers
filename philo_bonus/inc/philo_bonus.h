/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassofi <eassofi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:47:10 by eassofi           #+#    #+#             */
/*   Updated: 2022/04/05 18:28:23 by eassofi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H
# include <semaphore.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>
# include  <sys/time.h>
# include <limits.h>
# include <string.h>
# include <signal.h>

typedef struct s_param
{
	int		nb_philos;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	int		must_to_eat;
	long	start;
	int		end;
	int		finished;
	int		*fork_state;
	sem_t	*sem_forks;
	sem_t	*sem_death;
	sem_t	*sem_message;
	sem_t	*sem_stop;
	sem_t	*sem_finish_eat;
}		t_param;

typedef struct s_philo
{
	int		philo_num;
	int		is_eating;
	int		nb_of_eat;
	long	last_eat;
	pid_t	pid;
	t_param	*param;
}		t_philo;

int		set_args(int ac, char **av, t_param *param);
int		ft_atoi(const char *str);
int		philo_process(t_param *param, t_philo *philo);
long	gettime(void);
sem_t	*ft_sem_init(const char *name, unsigned int value);
void	ft_sleep(useconds_t time);
void	print_state(t_philo *philo, char *s);
void	philo_thinking(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_life(t_philo *philo);
void	philo_eat(t_philo *philo);
void	check_philo_must_eat(t_philo *philo);
int		create_threads(pthread_t th, t_philo *philo);
t_philo	*set_philo(t_param *param);
void	*check_death(void *arg);
void	free_philo(t_philo *philo, t_param *param);
int		create_semaphores(t_param *param);
#endif