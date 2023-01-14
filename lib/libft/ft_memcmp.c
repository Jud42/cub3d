/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btchiman <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 20:19:40 by btchiman          #+#    #+#             */
/*   Updated: 2021/11/11 21:05:38 by Blaze            ###    42Lausanne.ch    */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*The memcmp() function compares byte string s1 against byte string s2.
 Both strings are assumed to be n bytes long.The memcmp() function returns
 zero if the two strings are identical,otherwise returns the difference between
 the first two differing bytes(treated as unsigned char values, so that `\200'
 is greater than `\0', for example).Zero-length strings are always identical.
 This behavior is not required by C and portable code should only depend on
 the sign of the returned value*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	unsigned int	i;

	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (str1[i] != str2[i])
		{
			return (str1[i] - str2[i]);
		}
		i++;
	}
	return (0);
}
