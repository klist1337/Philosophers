/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassofi <eassofi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 02:04:27 by eassofi           #+#    #+#             */
/*   Updated: 2022/04/05 16:39:47 by eassofi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_philo_must_to_eat(t_philo *philo)
{
	if (philo->param->must_to_eat > 0
		&& ++philo->num_eat == philo->param->must_to_eat)
	{
		if (++philo->param->finish_eat == philo->param->nb_philos)
		{
			philo->param->end = 1;
			pthread_mutex_lock(&philo->param->mutex_end);
		}
	}
}

void	philo_thinking(t_philo *philo)
{
	print_state(philo, "is thinking");
}

void	philo_sleep(t_philo	*philo)
{
	print_state(philo, "is sleeping");
	ft_sleep(philo->param->time_to_sleep * 1000);
}

void	philo_eat(t_philo *philo)
{	
	while (1)
	{
		if (philo->param->forks_state[philo->rght_fork] == FREE)
		{
			pthread_mutex_lock(&philo->param->forks[philo->rght_fork]);
			philo->param->forks_state[philo->rght_fork] = LOCK;
			print_state(philo, "has taken a fork");
			pthread_mutex_lock(&philo->param->forks[philo->lft_fork]);
			philo->param->forks_state[philo->lft_fork] = LOCK;
			print_state(philo, "has taken a fork");
			philo ->is_eating = 1;
			philo->last_eat = gettime();
			print_state(philo, "is eating");
			check_philo_must_to_eat(philo);
			ft_sleep(philo->param->time_to_eat * 1000);
			philo ->is_eating = 0;
			philo->param->forks_state[philo->rght_fork] = FREE;
			philo->param->forks_state[philo->lft_fork] = FREE;
			pthread_mutex_unlock(&philo->param->forks[philo->rght_fork]);
			pthread_mutex_unlock(&philo->param->forks[philo->lft_fork]);
			break ;
		}
		else
			usleep(100);
	}
}

void	*philo_life(void *arg)
{
	while (1)
	{
		philo_eat((t_philo *)arg);
		philo_sleep((t_philo *)arg);
		philo_thinking((t_philo *)arg);
	}
	return (NULL);
}
