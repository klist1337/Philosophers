/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassofi <eassofi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:41:43 by eassofi           #+#    #+#             */
/*   Updated: 2022/04/05 18:40:19 by eassofi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int ac, char **av)
{
	t_param		*param;
	t_philo		*philo;
	int			i;

	i = 0;
	param = malloc(sizeof(t_param));
	if (!set_args(ac, av, param))
		return (1);
	philo = set_philo(param);
	if (!create_semaphores(param))
		return (1);
	if (!philo || !philo_process(param, philo))
		return (1);
	free_philo(philo, param);
}
