/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btchiman <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:51:50 by btchiman          #+#    #+#             */
/*   Updated: 2021/11/12 01:03:12 by Blaze            ###    42Lausanne.ch    */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Alloue (avec malloc(3)) et retourne une chaine de caractères issue de la 
chaine ’s’.Cette nouvelle chaine commence à l’index ’start’ et a pour taille
maximale ’len’
#1. La chaine de laquelle extraire la nouvelle chaine
#2. L’index de début de la nouvelle chaine dans la chaine ’s’.
#3. La taille maximale de la nouvelle chaine.
return la nouvelle chaine de caractere ou NULL si l'allocation échoue.*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	idx;
	size_t			count;
	size_t			len_start;

	idx = start;
	count = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	len_start = ft_strlen(s + start);
	if (len_start < len)
		len = len_start;
	substr = (char *) malloc((len + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	while (count < len && s[idx] != '\0')
	{
		substr[count] = s[idx];
		idx++;
		count++;
	}
	substr[count] = '\0';
	return (substr);
}
