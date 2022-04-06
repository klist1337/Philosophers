/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassofi <eassofi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:26:15 by eassofi           #+#    #+#             */
/*   Updated: 2022/04/05 16:53:38 by eassofi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	set_args(int ac, char **av, t_param *param)
{
	if (ac - 1 != 4 && ac - 1 != 5)
	{
		write(2, "Error : args must be 4 or 5\n", 29);
		return (0);
	}
	param->nb_philos = ft_atoi(av[1]);
	param ->time_to_die = ft_atoi(av[2]);
	param ->time_to_eat = ft_atoi(av[3]);
	param ->time_to_sleep = ft_atoi(av[4]);
	if (ac - 1 == 5)
		param ->must_to_eat = ft_atoi(av[5]);
	else
		param ->must_to_eat = 0;
	if (param->nb_philos < 1 || param->time_to_die < 1
		|| param->time_to_eat < 1 || param->time_to_sleep < 1
		|| (ac == 6 && param->must_to_eat < 1))
		return (0);
	return (1);
}

int	init_mutex(t_param *param)
{
	int	i;

	i = 0;
	while (i < param->nb_philos)
	{
		if (pthread_mutex_init(&param->forks[i], NULL))
		{
			write(2, "Mutex init failed\n", 19);
			return (0);
		}
		i++;
	}
	return (1);
}

int	set_param(t_param *param)
{
	param ->forks = malloc(sizeof(pthread_mutex_t) * param->nb_philos);
	param->forks_state = malloc(sizeof(int) * param->nb_philos);
	memset(param->forks_state, FREE, sizeof(int) * param->nb_philos);
	if (!param->forks_state || !param->forks)
	{
		write(2, "Error : MALLOC FAILED\n", 23);
		return (0);
	}
	if (!init_mutex(param) || pthread_mutex_init(&param->mutex_end, NULL))
	{
		write(2, "Error : MUTEX INIT FAILED\n", 27);
		return (0);
	}
	param->end = 0;
	param->finish_eat = 0;
	param ->start = gettime();
	return (1);
}

t_philo	*set_philo(t_param *param)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)malloc(sizeof(t_philo) * param->nb_philos);
	if (philo == NULL)
	{
		write(2, "Error : MALLOC FAILED\n", 23);
		return (NULL);
	}
	i = 0;
	while (i < param->nb_philos)
	{
		philo[i].number = i + 1;
		philo[i].lft_fork = i;
		if (i == 0)
			philo[i].rght_fork = param->nb_philos - 1;
		else
			philo[i].rght_fork = i - 1;
		philo[i].last_eat = param->start;
		philo[i].param = param;
		philo[i].num_eat = 0;
		philo[i].is_eating = 0;
		i++;
	}
	return (philo);
}
