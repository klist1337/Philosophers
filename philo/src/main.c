/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassofi <eassofi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 14:40:43 by eassofi           #+#    #+#             */
/*   Updated: 2022/04/05 17:06:29 by eassofi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_start(pthread_t *th, t_param *param, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < param->nb_philos)
	{
		if (pthread_create(&th[i], NULL, philo_life, &philo[i]))
		{
			write(2, "Failed to create threads\n", 26);
			return (0);
		}
		usleep(50);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_param		params;
	pthread_t	*p;
	t_philo		*philo;

	if (!set_args(ac, av, &params) || !set_param(&params))
		return (1);
	philo = set_philo(&params);
	p = (pthread_t *)malloc(sizeof(pthread_t) * params.nb_philos);
	if (!philo || !p || !philo_start(p, &params, philo))
		return (1);
	check_philo_death(philo, &params);
	free_philo(philo, &params, p);
	return (0);
}
