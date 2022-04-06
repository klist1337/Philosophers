/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassofi <eassofi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:17:41 by eassofi           #+#    #+#             */
/*   Updated: 2022/04/06 16:16:48 by eassofi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*check_death(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		sem_wait(philo->param->sem_death);
		if (philo->is_eating == 0 && (gettime() - philo->last_eat) / 1000
			>= philo->param->time_to_die)
		{
			sem_wait(philo->param->sem_message);
			printf("[%ld] (%d) %s", (gettime() - philo->param->start) / 1000,
				philo->philo_num, "is died\n");
			sem_post(philo->param->sem_stop);
			return (0);
		}
		sem_post(philo->param->sem_death);
	}
	return (NULL);
}

void	free_philo(t_philo *philo, t_param *param)
{
	free(param);
	free(philo);
}
