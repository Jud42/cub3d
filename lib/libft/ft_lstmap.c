/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btchiman <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:23:20 by btchiman          #+#    #+#             */
/*   Updated: 2021/11/19 00:03:09 by Blaze            ###    42Lausanne.ch    */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Itère sur la liste lst et applique la fonction f au contenu de chaque 
élément.Crée une nouvelle liste résultant des applications successives de f.
la fonction del est la pour detruire le contenu d un element si necessaire
#1. L’adresse du pointeur vers un élément.
#2. L’adresse de la fonction à appliquer.
return la nouvelle liste ou Null si malloc echoue*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void*))
{
	const t_list	*lstp = lst;
	t_list			*ret;
	t_list			*new;

	ret = NULL;
	new = NULL;
	while (lstp)
	{
		new = ft_lstnew(f(lstp->content));
		if (!new)
		{
			ft_lstclear(&lst, del);
			return (NULL);
		}
		ft_lstadd_back(&ret, new);
		lstp = lstp->next;
	}
	return (ret);
}
