/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btchiman <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:52:49 by btchiman          #+#    #+#             */
/*   Updated: 2021/11/11 20:47:54 by Blaze            ###    42Lausanne.ch    */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Renvoie le dernier élément de la liste.
 * parametre: debut de liste
 */

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last;

	last = lst;
	if (last)
	{
		while (last->next)
			last = last->next;
	}
	return (last);
}
