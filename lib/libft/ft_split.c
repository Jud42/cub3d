/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btchiman <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 18:15:16 by btchiman          #+#    #+#             */
/*   Updated: 2021/11/12 00:47:01 by Blaze            ###    42Lausanne.ch    */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Alloue (avec malloc(3)) et retourne un tableau
de chaines de caracteres obtenu en séparant ’s’ à l’aide du caractère ’c’, 
utilisé comme délimiteur. Le tableau doit être terminé par NULL.

#1. La chaine de caractères à découper.
#2. Le caractère délimitant.

Return
Le tableau de nouvelles chaines de caractères, résultant du découpage.
NULL si l’allocation échoue. */

static size_t	ft_count_words(char const *s, char c)
{
	size_t	n;
	size_t	i;

	i = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			n++;
			while (s[i] != c && s[i] != '\0')
			{
				i++;
			}
		}
	}
	return (n);
}

static char	**ft_get_words(char const *s, char c, size_t num_words, char **arr)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (num_words--)
	{
		i = 0;
		while (*s == c)
			s++;
		while (s[i] != c && s[i] != '\0')
			i++;
		arr[j] = (char *)malloc((i + 1) * sizeof(char));
		if (!*arr)
			return (NULL);
		i = 0;
		while (*s != c && *s)
			arr[j][i++] = *s++;
		arr[j][i] = '\0';
		j++;
	}
	arr[j] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	size_t	num_words;
	char	**arr;

	if (!s)
		return (NULL);
	num_words = ft_count_words(s, c);
	arr = (char **)malloc((num_words + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	arr = ft_get_words(s, c, num_words, arr);
	return (arr);
}
