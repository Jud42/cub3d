/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btchiman <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:13:04 by btchiman          #+#    #+#             */
/*   Updated: 2021/11/12 00:18:54 by Blaze            ###    42Lausanne.ch    */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Alloue (avec malloc(3)) et retourne une nouvelle chaine, résultat de la 
concaténation de s1 et s2.
#1. La chaine de caractères préfixe.
#2. La chaine de caractères suffixe.

retourne La nouvelle chaine de caractères. NULL si l’allocation échoue.*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	len;
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ((ft_strlen(s1) + ft_strlen(s2)) + 1);
	newstr = malloc(len * sizeof(char));
	if (!newstr)
		return (NULL);
	while (i < len && *s1 != '\0')
	{
		newstr[i] = *s1;
		i++;
		s1++;
	}
	while (i < len && *s2 != '\0')
	{
		newstr[i] = *s2;
		i++;
		s2++;
	}
	newstr[i] = '\0';
	return (newstr);
}
