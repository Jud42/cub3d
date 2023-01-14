/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btchiman <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 20:12:26 by btchiman          #+#    #+#             */
/*   Updated: 2021/11/12 00:55:03 by Blaze            ###    42Lausanne.ch    */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*The memchr() function locates the first occurrence of c (converted to an 
unsigned char) in string s.*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	p;
	unsigned char	*str;

	p = (unsigned char) c;
	str = (unsigned char *)s;
	while (n--)
	{
		if (*str == p)
			return (str);
		str++;
	}
	return (NULL);
}
