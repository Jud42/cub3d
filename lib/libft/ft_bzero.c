/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btchiman <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 16:46:56 by btchiman          #+#    #+#             */
/*   Updated: 2021/10/29 17:27:45 by btchiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/*The bzero() function writes n zeroed bytes to the string s.
 * If n is zero, bzero() does nothing.
*/

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
