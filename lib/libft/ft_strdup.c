/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btchiman <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 20:30:59 by btchiman          #+#    #+#             */
/*   Updated: 2021/11/12 01:15:29 by Blaze            ###    42Lausanne.ch    */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*The strdup() function allocates sufficient memory for a copy of the string s1
does the copy, and returns a pointer to it.  The pointer may subsequently be 
used as an argument to the function free(3).

If insufficient memory is available, NULL is returned and errno 
is set to ENOMEM.*/

char	*ft_strdup(const char *s1)
{
	size_t	size;
	char	*ptr;
	size_t	idx;

	idx = 0;
	size = 0;
	while (s1[size] != '\0')
		size++;
	ptr = malloc((size + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	while (idx < size)
	{
		ptr[idx] = s1[idx];
		idx++;
	}
	ptr[size] = '\0';
	return (ptr);
}
