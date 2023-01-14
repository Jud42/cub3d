/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btchiman <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 19:53:14 by btchiman          #+#    #+#             */
/*   Updated: 2021/11/11 18:00:19 by Blaze            ###    42Lausanne.ch    */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Écrit la chaine de caractères ’s’ sur le file descriptor donné.
#1. La chaine de caractères à écrire.
#2. Le file descriptor sur lequel écrire.*/

void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;

	len = ft_strlen(s);
	if (!s)
		return ;
	else
		write(fd, s, len);
}
