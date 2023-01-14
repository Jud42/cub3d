/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btchiman <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:08:17 by btchiman          #+#    #+#             */
/*   Updated: 2021/11/15 21:28:40 by btchiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(const char *str)
{
	long			res;
	long			sign;
	long			i;

	res = 0;
	sign = 1;
	i = 0;
	while ((str[i] <= 13 && str[i] >= 9) || (str[i] == 32))
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
		res = res * 10 + (str[i++] - '0');
	return ((int)(res * sign));
}
