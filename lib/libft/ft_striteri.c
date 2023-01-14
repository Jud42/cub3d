/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btchiman <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 19:13:26 by btchiman          #+#    #+#             */
/*   Updated: 2021/11/12 00:13:32 by Blaze            ###    42Lausanne.ch    */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Applique la fonction f à chaque caractère de la chaîne de caractères
transmise comme argument, et en passant son index comme premier argument.
Chaque caractère est transmis par adresse à f pour être modifié si nécessaire.
 * #1. La chaine de caractères sur laquelle itérer.
 * #2. La fonction à appliquer à chaque caractère. None.*/

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	if (!s || !f)
		return ;
	i = -1;
	while (s[++i] != '\0')
		(*f)(i, &s[i]);
}
