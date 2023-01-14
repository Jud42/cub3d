/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btchiman <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:33:00 by btchiman          #+#    #+#             */
/*   Updated: 2021/11/11 22:31:14 by Blaze            ###    42Lausanne.ch    */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Supprime et libère la mémoire de l’élément passé en paramètre, et de tous
les élements qui suivent, à l’aide de del et de free(3)
Enfin, le pointeur initial doit être mis à NULL.
#1. L’adresse du pointeur vers un élément.
#2. L’adresse de la fonction permettant de supprimer le contenu d’un élément.*/

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*current;

	if (lst && del)
	{
		tmp = *lst;
		while (tmp)
		{
			current = tmp;
			del(tmp->content);
			free(tmp);
			tmp = current->next;
		}
		*lst = NULL;
	}
}
