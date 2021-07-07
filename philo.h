/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-biha <fle-biha@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 00:58:22 by fle-biha          #+#    #+#             */
/*   Updated: 2021/07/06 12:35:32 by fle-biha         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	int	nmb_philo;
	int	t_to_die;
	int	t_to_eat;
	int	t_to_sleep;
	int	nmb_of_eat;
	int	six_p;
}t_philo;

typedef struct s_arg
{
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_philo			*stock;
	int				i;
}t_arg;

int		ft_isdigit(int c);
void	ft_bzero(void *s, size_t n);
int		ft_atoi(const char *str);

#endif
