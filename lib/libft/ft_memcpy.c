/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btchiman <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 19:12:37 by btchiman          #+#    #+#             */
/*   Updated: 2021/11/15 15:16:11 by btchiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*The memcpy()function copies n bytes from memory area src to memory area dst.  
 If dst and src overlap, behavior is undefined.  Applications in which dst
 and src might overlap should use memmove(3) instead.
 The memcpy() function returns the original value of dst.*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	if (dst == src || n == 0)
		return (dst);
	str1 = (unsigned char *)dst;
	str2 = (unsigned char *)src;
	while (n--)
		*str1++ = *str2++;
	return (dst);
}
