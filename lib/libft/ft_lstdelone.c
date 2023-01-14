/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btchiman <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 21:04:14 by btchiman          #+#    #+#             */
/*   Updated: 2021/11/12 01:19:28 by Blaze            ###    42Lausanne.ch    */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Libère la mémoire de l’élément passé en argument en utilisant la fonction
del puis avec free(3). La mémoire de next ne doit pas être free.
#1. L’élement à free
#2. L’adresse de la fonction permettant de supprimer le contenu de l’élement.*/

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst && del)
	{
		del(lst->content);
		free(lst);
	}
}
