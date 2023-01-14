/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btchiman <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 20:26:48 by btchiman          #+#    #+#             */
/*   Updated: 2021/11/12 01:11:37 by Blaze            ###    42Lausanne.ch    */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*The malloc(), calloc(), valloc(), realloc(), and reallocf() functions
allocate memory.  
* The allocated memory is aligned such that it can be used for any data type,
* including AltiVec- and SSE-related types.  The aligned_alloc() function
allocates  memory with the requested alignment.The free() function frees 
allocations that were
created via the preceding allocation functions.
The malloc() function allocates size bytes 
of memory and returns a pointer to the allocated memory.
The calloc() function contiguously allocates enough space for count objects 
that are size bytes of memory each and returns a pointer to the allocated memory.
The allocated memory is filled with bytes of value zero.*/

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, (count * size));
	return (ptr);
}
