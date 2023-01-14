/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btchiman <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 19:33:36 by btchiman          #+#    #+#             */
/*   Updated: 2021/11/15 15:17:17 by btchiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The strlcpy() and strlcat() functions copy and concatenate strings with 
the same input parameters and output result as snprintf(3).They are designed
to be safer, more consistent, and less error prone replacements for the easily
misused functions strncpy(3) and strncat(3).

strlcpy() and strlcat() take the full size of the destination buffer and
guarantee NUL-termination if there is room.  Note that room for the NUL should
be included in dstsize.

strlcpy() copies up to dstsize - 1 characters from the string src to dst,
NUL-terminating the result if dstsize is not 0.

strlcat() appends string src to the end of dst.  It will append at most dstsize
-strlen(dst) - 1 characters.  It will then NUL-terminate, unless dstsize is 0
or the original dst string was longer than dstsize (in practice this should not
happen as it means that either dstsize is incorrect or that dst is not a proper
string).

If the src and dst strings overlap, the behavior is undefined.*/

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	index_src;
	size_t	len_dst;
	size_t	len_src;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (size <= len_dst)
		return (size + len_src);
	index_src = 0;
	while (src[index_src] != '\0' && size > (len_dst + 1))
	{
		dst[len_dst] = src[index_src];
		index_src++;
		len_dst++;
	}
	dst[len_dst] = '\0';
	return (len_dst + ft_strlen((&src[index_src])));
}
