/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btchiman <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 20:27:29 by btchiman          #+#    #+#             */
/*   Updated: 2021/11/16 16:55:19 by Blaze            ###    42Lausanne.ch    */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 Ajoute l’élément new à la fin de la liste.
 #1. L’adresse du pointeur vers le premier élément de la liste.
 #2. L’adresse du pointeur vers l’élément à rajouter à la liste.
*/

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*tmp;

	if (*alst == NULL)
		*alst = new;
	else
	{
		tmp = *alst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}
