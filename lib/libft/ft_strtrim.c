/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btchiman <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 17:16:07 by btchiman          #+#    #+#             */
/*   Updated: 2021/11/12 01:06:23 by Blaze            ###    42Lausanne.ch    */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Alloue (avec malloc(3)) et retourne une copie de la chaine ’s1’, sans les 
caractères spécifiés dans ’set’ au début et à la fin de la chaine de caractères.

#1. La chaine de caractères à trimmer.
#2. Le set de reference de caractères à trimmer.

retourne La chaine de caractères trimmée. NULL si l’allocation échoue.
*/

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		++s1;
	len = ft_strlen(s1);
	while (len && ft_strchr(set, s1[len]))
		--len;
	return (ft_substr(s1, 0, (len + 1)));
}
