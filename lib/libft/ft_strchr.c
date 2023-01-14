/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btchiman <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 20:01:41 by btchiman          #+#    #+#             */
/*   Updated: 2021/11/15 19:38:59 by btchiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*The strchr() function locates the first occurrence of c (converted to a char)
in the string pointed to by s.  The terminating null character is considered to
be part of the string; therefore if c is `\0', the functions locate the
terminating `\0'.

The strrchr() function is identical to strchr(), except it locates the last
occurrence of c.

The functions strchr() and strrchr() return a pointer to the located character,
or NULL if the character does not appear in the string.*/

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != (char)c)
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return (str);
}
