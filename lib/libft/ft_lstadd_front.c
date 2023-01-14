/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btchiman <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:51:00 by btchiman          #+#    #+#             */
/*   Updated: 2021/11/12 00:49:44 by Blaze            ###    42Lausanne.ch    */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Ajoute l’élément ’new’ au début de la liste.
#1. L’adresse du pointeur vers le premier élément de la liste.
#2. L’adresse du pointeur vers l’élément à rajouter à la liste.*/

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (alst && new)
	{
		new->next = *alst;
		*alst = new;
	}
}
