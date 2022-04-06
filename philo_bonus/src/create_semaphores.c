/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_semaphores.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassofi <eassofi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 03:24:22 by eassofi           #+#    #+#             */
/*   Updated: 2022/04/05 03:27:50 by eassofi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	create_semaphores(t_param *param)
{
	sem_unlink("sem_forks");
	sem_unlink("sem_message");
	sem_unlink("sem_stop");
	sem_unlink("sem_death");
	sem_unlink("sem_finish_eat");
	param->sem_finish_eat = sem_open("sem_finish_eat", O_CREAT, 0600, 0);
	param->sem_forks = sem_open("sem_forks", O_CREAT, 0600, param->nb_philos);
	param->sem_message = sem_open("sem_message", O_CREAT, 0600, 1);
	param->sem_stop = sem_open("sem_stop", O_CREAT, 0600, 0);
	param->sem_death = sem_open("sem_death", O_CREAT, 0600, 1);
	if (param->sem_forks == SEM_FAILED
		|| param->sem_message == SEM_FAILED
		|| param->sem_death == SEM_FAILED)
	{
		write(2, "sem failed\n", 12);
		return (0);
	}
	return (1);
}
