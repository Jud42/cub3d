/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btchiman <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 19:47:07 by btchiman          #+#    #+#             */
/*   Updated: 2021/11/12 00:44:06 by Blaze            ###    42Lausanne.ch    */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The toupper() function converts a lower-case letter to the corresponding
upper-case letter. The argument must be representable as an unsigned char or 
the value of EOF.*/

int	ft_toupper(int c)
{
	while (c >= 97 && c <= 122)
		c = c - 32;
	return (c);
}
