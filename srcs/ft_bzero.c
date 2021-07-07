/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-biha <fle-biha@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 16:04:42 by fle-biha          #+#    #+#             */
/*   Updated: 2021/07/05 01:10:05 by fle-biha         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_bzero(void *s, size_t n)
{
	char	*tmp;
	size_t	i_tmp;

	i_tmp = 0;
	tmp = (char *)s;
	while (i_tmp < n)
		tmp[i_tmp++] = 0;
}
