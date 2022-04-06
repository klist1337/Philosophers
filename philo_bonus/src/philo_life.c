/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassofi <eassofi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 15:44:00 by eassofi           #+#    #+#             */
/*   Updated: 2022/04/06 16:32:42 by eassofi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	philo_eat(t_philo *philo)
{
	sem_wait(philo->param->sem_forks);
	print_state(philo, "has taken a fork\n");
	sem_wait(philo->param->sem_forks);
	print_state(philo, "has taken a fork\n");
	philo->last_eat = gettime();
	print_state(philo, "is eating\n");
	philo->is_eating = 1;
	philo->nb_of_eat++;
	if (philo->param->must_to_eat > 0
		&& philo->nb_of_eat == philo->param->must_to_eat)
	{
		sem_post(philo ->param->sem_finish_eat);
		sem_post(philo->param->sem_message);
	}
	ft_sleep(philo->param->time_to_eat * 1000);
	philo->is_eating = 0;
	sem_post(philo->param->sem_forks);
	sem_post(philo->param->sem_forks);
}

void	philo_sleep(t_philo *philo)
{
	print_state(philo, "is sleeping\n");
	ft_sleep(philo->param->time_to_sleep * 1000);
}

void	philo_thinking(t_philo *philo)
{
	print_state(philo, "is thinking\n");
}

void	philo_life(t_philo *philo)
{
	pthread_t	th;
	int			i;

	i = 0;
	pthread_create(&th, NULL, check_death, philo);
	philo->last_eat = gettime();
	while (1)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_thinking(philo);
	}
	exit(0);
}
