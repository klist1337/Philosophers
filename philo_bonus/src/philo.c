/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassofi <eassofi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 00:00:56 by eassofi           #+#    #+#             */
/*   Updated: 2022/04/06 16:30:11 by eassofi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*check_eat(void *arg)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = (t_philo *)arg;
	while (i < philo->param->nb_philos)
	{
		sem_wait(philo->param->sem_finish_eat);
		i++;
	}
	sem_post(philo->param->sem_stop);
	return (NULL);
}

void	kill_proc(t_param *param, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < param ->nb_philos)
	{
		kill(philo[i].pid, SIGKILL);
		i++;
	}	
}

int	philo_process(t_param *param, t_philo *philo)
{
	int			i;
	pthread_t	check_eating;
	long		start;

	i = -1;
	start = gettime();
	while (++i < param->nb_philos)
	{
		philo[i].param->start = start;
		philo[i].pid = fork();
		if (philo[i].pid == 0)
		{
			philo_life(&philo[i]);
			return (0);
		}
		else if (philo[i].pid < 0)
		{
			write(2, "ERROR: FORK FAILED", 19);
		}
	}
	pthread_create(&check_eating, NULL, check_eat, philo);
	pthread_detach(check_eating);
	sem_wait(param ->sem_stop);
	kill_proc(param, philo);
	return (1);
}

int	set_args(int ac, char **av, t_param *param)
{
	if (ac - 1 != 4 && ac - 1 != 5)
	{
		write (2, "ERROR : args must be 5 or 6\n", 29);
		return (0);
	}
	param->nb_philos = ft_atoi(av[1]);
	param->time_to_die = ft_atoi(av[2]);
	param->time_to_eat = ft_atoi(av[3]);
	param->time_to_sleep = ft_atoi(av[4]);
	if (ac - 1 == 5)
		param->must_to_eat = ft_atoi(av[5]);
	else
		param->must_to_eat = 0;
	if (param->nb_philos < 1 || param->time_to_die < 1
		|| param->time_to_eat < 1 || param->time_to_sleep < 1
		|| (ac == 6 && param->must_to_eat < 1))
		return (0);
	param->start = gettime();
	param->finished = 0;
	param->end = 0;
	return (1);
}

t_philo	*set_philo(t_param *param)
{
	t_philo	*philo;
	int		i;

	philo = malloc(sizeof(t_philo) * param->nb_philos);
	if (!philo)
		return (NULL);
	i = 0;
	while (i < param->nb_philos)
	{
		philo[i].philo_num = i + 1;
		philo[i].param = param;
		philo[i].is_eating = 0;
		philo[i].last_eat = param->start;
		philo[i].nb_of_eat = 0;
		i++;
	}
	return (philo);
}
