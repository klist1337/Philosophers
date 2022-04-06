/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassofi <eassofi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 16:05:26 by eassofi           #+#    #+#             */
/*   Updated: 2022/04/05 16:38:31 by eassofi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/time.h>
# include <limits.h>
# include <string.h>

# define FREE 0
# define LOCK 1

typedef struct s_param
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	mutex_end;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				nb_philos;
	int				must_to_eat;
	int				*forks_state;
	int				finish_eat;
	int				end;
	long			start;
}	t_param;

typedef struct s_philo
{
	t_param	*param;
	int		rght_fork;
	int		lft_fork;
	int		num_eat;
	int		is_eating;
	int		number;
	long	last_eat;
	int		finish_eat;
}	t_philo;

int		ft_atoi(const char *str);
int		set_args(int ac, char **av, t_param *param);
int		init_mutex(t_param *param);
int		set_param(t_param *param);
t_philo	*set_philo(t_param *param);
long	gettime(void);
void	ft_sleep(useconds_t time);
void	print_state(t_philo *philo, char *s);
void	check_philo_must_to_eat(t_philo *philo);
void	philo_thinking(t_philo *philo);
void	philo_sleep(t_philo	*philo);
void	philo_eat(t_philo *philo);
void	*philo_life(void *arg);
int		philo_start(pthread_t *th, t_param *param, t_philo *philo);
void	check_philo(t_philo *philo);
void	destroy_forks_mutex(t_param *param);
void	check_philo_death(t_philo *philo, t_param *param);
void	free_philo(t_philo *philo, t_param *param, pthread_t *p);
#endif