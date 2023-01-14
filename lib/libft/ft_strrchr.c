/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btchiman <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 20:04:42 by btchiman          #+#    #+#             */
/*   Updated: 2021/11/15 19:38:02 by btchiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*The strchr() function locates the first occurrence of c (converted to a char)
in the string pointed to by s.  The terminating null character is considered
to be part of
the string; therefore if c is `\0', the functions locate the terminating `\0'.
The strrchr() function is identical to strchr(), except it locates the
last occurrence of c.*/

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		i;

	i = ft_strlen(s);
	str = (char *)s;
	while (i >= 0)
	{
		if (str[i] == (char)c)
			return (str + i);
		i--;
	}	
	return (NULL);
}
