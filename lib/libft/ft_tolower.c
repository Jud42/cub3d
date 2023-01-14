/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btchiman <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 19:51:26 by btchiman          #+#    #+#             */
/*   Updated: 2021/11/12 01:27:52 by Blaze            ###    42Lausanne.ch    */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*The tolower() function converts an upper-case letter to the corresponding
lower-case letter.  The argument must be representable as an unsigned char or 
the value of EOF.*/

int	ft_tolower(int c)
{
	while (c >= 65 && c <= 90)
		c = c + 32;
	return (c);
}
