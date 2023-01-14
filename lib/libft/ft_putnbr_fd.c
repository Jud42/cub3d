/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btchiman <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 21:04:08 by btchiman          #+#    #+#             */
/*   Updated: 2021/11/06 21:10:50 by btchiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Écrit l’integer ’n’ sur le file descriptor donné.
#1. L’integer à écrire.
#2. Le file descriptor sur lequel écrire.*/

void	ft_putnbr_fd(int n, int fd)
{
	char	nbr;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
	}
	else if (n == 0)
	{
		write (fd, "0", 1);
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
		ft_putnbr_fd(n, fd);
	}
	else if (n > 0)
	{
		if (n / 10 != 0)
			ft_putnbr_fd(n / 10, fd);
		nbr = n % 10 + '0';
		write (fd, &nbr, 1);
	}
}
