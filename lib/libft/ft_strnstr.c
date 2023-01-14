/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btchiman <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 20:24:14 by btchiman          #+#    #+#             */
/*   Updated: 2021/11/11 13:56:45 by Blaze            ###    42Lausanne.ch    */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*The strnstr() function locates the first occurrence of the null-terminated 
string needle in the string haystack, where not more than len characters are 
searched.  Characters that appear after a `\0' character are not searched.  
Since the strnstr() function is a FreeBSD specific API, it should only be 
used when portability is not a concern.
RETURN VALUES
If needle is an empty string, haystack is returned; if needle occurs
nowhere in haystack, NULL is returned; otherwise a pointer to the first
character of the first occurrence of needle is returned.*/

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	c;

	if (needle[0] == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] != '\0' && i < len)
	{
		c = 0;
		while ((haystack[i + c] == needle[c]) && (i + c) < len)
		{
			if (needle[c + 1] == '\0')
				return ((char *)(&haystack[i]));
			c++;
		}
		i++;
	}
	return (NULL);
}
