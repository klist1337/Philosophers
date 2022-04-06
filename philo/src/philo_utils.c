/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassofi <eassofi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 01:50:15 by eassofi           #+#    #+#             */
/*   Updated: 2022/04/05 18:35:33 by eassofi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	gettime(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000000 + time.tv_usec));
}

void	ft_sleep(useconds_t time)
{
	long	t;

	t = gettime();
	while (gettime() - t < time)
		usleep(1);
}

static int	ft_isspace(char c)
{
	return (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ');
}

int	ft_atoi(const char *str)
{
	int	r;
	int	sign;

	r = 0;
	sign = 1;
	if (*str == '\0')
		return (0);
	while (ft_isspace(*str))
	{
		str++;
	}
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		if (r > INT_MAX)
			return (-1);
		r = r * 10 + *str++ - '0';
	}
	return (sign * r);
}

void	print_state(t_philo *philo, char *s)
{
	pthread_mutex_lock(&philo->param->mutex_end);
	printf("[%ld] (%d) %s\n", (gettime() - philo->param->start) / 1000,
		philo->number, s);
	pthread_mutex_unlock(&philo->param->mutex_end);
}
