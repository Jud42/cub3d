/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btchiman <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:33:20 by btchiman          #+#    #+#             */
/*   Updated: 2021/10/27 16:58:50 by btchiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The memset() function writes len bytes of value c
 * (converted to an unsigned char)
 * to  the string b.
   The memset() function returns its first argument.*/

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;

	p = (unsigned char *) b;
	while (len > 0)
	{
		p[len - 1] = c;
		len--;
	}	
	return (b);
}
