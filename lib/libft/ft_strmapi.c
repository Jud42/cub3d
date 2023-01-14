/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btchiman <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 19:06:27 by btchiman          #+#    #+#             */
/*   Updated: 2021/11/11 21:11:54 by Blaze            ###    42Lausanne.ch    */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Applique la fonction ’f’ à chaque caractère de la chaine de caractères passée
en argument pour créer une nouvelle chaine de caractères (avec malloc(3))
résultant des applications successives de ’f’.
 #1. La chaine de caractères sur laquelle itérer
 #2. La fonction à appliquer à chaque caractère.
return La chaine de caractères résultant des applications successives de f.
Retourne NULL si l’allocation échoue.*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new_str;
	unsigned int	idx;

	if (!s || !f)
		return (NULL);
	new_str = (char *)malloc((ft_strlen(s) + 1) * sizeof(*new_str));
	if (new_str == NULL)
		return (NULL);
	idx = 0;
	while (s[idx] != '\0')
	{
		new_str[idx] = (*f)(idx, s[idx]);
		idx++;
	}
	new_str[idx] = '\0';
	return (new_str);
}
