/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-biha <fle-biha@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 00:48:45 by fle-biha          #+#    #+#             */
/*   Updated: 2021/07/07 15:49:23 by fle-biha         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	verif_arg(int ac, char **av)
{
	int	i;
	int	i2;

	i = 0;
	while (++i < ac)
	{
		i2 = -1;
		while (av[i][++i2])
			if (!(ft_isdigit(av[i][i2])))
				return (0);
	}
	return (1);
}

void	ft_fill_stock(int ac, char **av, t_philo *stock)
{
	stock->nmb_philo = ft_atoi(av[1]);
	stock->t_to_die = ft_atoi(av[2]);
	stock->t_to_eat = ft_atoi(av[3]);
	stock->t_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
	{
		stock->nmb_of_eat = ft_atoi(av[5]);
		stock->six_p = 1;
	}
}

void	*philo_life(void *data)
{
	t_arg			*arg;
	struct timeval	time;

	gettimeofday(&time, NULL);
	arg = (t_arg *)data;
	while (1)
	{
		pthread_mutex_lock(arg->left_fork);
		dprintf(1, "%ld ms %d has taken a fork\n", time.tv_sec * 1000, arg->i);
		pthread_mutex_lock(arg->right_fork);
		dprintf(1, "%ld ms %d has taken a fork\n", time.tv_sec * 1000, arg->i);
		dprintf(1, "%ld ms %d is eating\n", time.tv_sec * 1000, arg->i);
		usleep(arg->stock->t_to_eat * 1000);
		pthread_mutex_unlock(arg->right_fork);
		pthread_mutex_unlock(arg->left_fork);
		dprintf(1, "%ld ms %d is sleeping\n", time.tv_sec * 1000, arg->i);
		usleep(arg->stock->t_to_sleep * 1000);
		dprintf(1, "%ld ms %d is thinking\n", time.tv_sec * 1000, arg->i);
	}
	return (0);
}

void	launch_thread(pthread_mutex_t *left_fork, \
pthread_mutex_t *right_fork, t_philo *stock, int i)
{
	t_arg		arg;
	pthread_t	philo;

	ft_bzero(&arg, sizeof(arg));
	dprintf(1, "testest\n");
	arg.left_fork = left_fork;
	arg.right_fork = right_fork;
	arg.stock = stock;
	arg.i = i + 1;
	pthread_create(&philo, NULL, philo_life, &arg);
}

void	philo(int ac, char **av)
{
	pthread_mutex_t	left_fork;
	pthread_mutex_t	right_fork;
	pthread_mutex_t	fork1;
	t_philo			stock;
	int				i;

	ft_bzero(&stock, sizeof(stock));
	ft_fill_stock(ac, av, &stock);
	pthread_mutex_init(&left_fork, NULL);
	fork1 = left_fork;
	i = -1;
	while (++i < stock.nmb_philo - 1)
	{
		pthread_mutex_init(&right_fork, NULL);
		launch_thread(&left_fork, &right_fork, &stock, i);
		dprintf(1, "p1 = %p\n", &left_fork);
		left_fork = right_fork;
		dprintf(1, "p2 = %p\n", &left_fork);
	}
	launch_thread(&left_fork, &fork1, &stock, i);
}

int	main(int ac, char **av)
{
	if (ac <= 4 || ac > 6)
		dprintf(1, "./philo number_of_philosophers time_to_die time_to_eat \
time_to_sleep [number_of_times_each_philosopher_must_eat]");
	if (!(verif_arg(ac, av)))
		dprintf(1, "./philo number_of_philosophers time_to_die time_to_eat \
time_to_sleep [number_of_times_each_philosopher_must_eat]");
	philo(ac, av);
}
