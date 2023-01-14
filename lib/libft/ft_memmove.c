/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btchiman <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 19:18:26 by btchiman          #+#    #+#             */
/*   Updated: 2021/11/15 20:59:48 by btchiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*The memmove() function copies len bytes from string src to string dst.
The two strings may overlap; the copy is always done in a non-destructive
manner.The memmove() function returns the original value of dst.*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*source;
	unsigned char	*dest;
	size_t			i;

	source = (unsigned char *)src;
	dest = (unsigned char *)dst;
	i = 0;
	if (!dst && !src)
		return (NULL);
	if (source < dest)
	{
		while (++i <= len)
		{
			dest[len - i] = source[len - i];
		}
	}
	else
	{
		while (len-- > 0)
			*(dest++) = *(source++);
	}
	return (dst);
}
