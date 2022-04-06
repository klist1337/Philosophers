/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassofi <eassofi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:55:57 by eassofi           #+#    #+#             */
/*   Updated: 2022/04/05 20:18:58 by eassofi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_philo(t_philo *philo)
{
	if (philo->is_eating == 0 && (gettime() - philo->last_eat) / 1000
		>= philo->param->time_to_die)
	{
		philo->param->end = 1;
		pthread_mutex_lock(&philo->param->mutex_end);
		printf("[%ld] (%d) %s\n", (gettime() - philo->param->start) / 1000,
			philo->number, "is died");
	}
}

void	destroy_forks_mutex(t_param *param)
{
	int	i;

	i = 0;
	while (i < param->nb_philos)
	{
		pthread_mutex_destroy(&param->forks[i]);
		i++;
	}
	return ;
}

void	check_philo_death(t_philo *philo, t_param *param)
{
	int	i;

	while (!param->end)
	{
		i = 0;
		while (!param->end && i < philo->param->nb_philos)
		{
			check_philo(&philo[i]);
			i++;
		}
	}
	return ;
}

void	free_philo(t_philo *philo, t_param *param, pthread_t *p)
{
	destroy_forks_mutex(param);
	free(param->forks_state);
	free(param->forks);
	pthread_mutex_destroy(&param->mutex_end);
	free(p);
	free(philo);
}
