/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btchiman <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:22:59 by btchiman          #+#    #+#             */
/*   Updated: 2021/11/11 18:58:56 by Blaze            ###    42Lausanne.ch    */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Alloue(avec malloc(3)) et renvoie
un nouvel élément. la variable content est initialisée
à l’aide de la valeur du paramètre content.
La variable ’next’ est initialisée à NULL*/

t_list	*ft_lstnew(void	*content)
{
	t_list	*elm;

	elm = malloc(sizeof(t_list));
	if (elm)
	{
		elm->content = content;
		elm->next = NULL;
	}
	return (elm);
}
