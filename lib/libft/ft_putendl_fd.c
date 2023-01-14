/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btchiman <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 20:51:14 by btchiman          #+#    #+#             */
/*   Updated: 2021/11/12 00:32:12 by Blaze            ###    42Lausanne.ch    */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Écrit La chaine de caractères ’s’ sur le file descriptor donné,
suivie d’un retour à la ligne.
#1. La chaine de caractères à écrire.
#2. Le file descriptor sur lequel écrire.*/

void	ft_putendl_fd(char *s, int fd)
{
	size_t	len;

	len = ft_strlen(s);
	if (!s)
		return ;
	if (s)
	{
		write(fd, s, len);
		write(fd, "\n", 1);
	}
}
