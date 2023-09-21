/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:18:14 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/09/21 17:52:43 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, int(*f)(int, t_list*))
{
	t_list	*newlist;
	t_list	*nxt;
	int		aux;

	newlist = NULL;
	nxt = newlist;
	while (lst)
	{
		aux = f(lst->content, lst);
		nxt = ft_lstnew(aux);
		if (!nxt)
		{
			ft_lstclear(&newlist);
			return (NULL);
		}
		ft_lstadd_back(&newlist, nxt);
		lst = lst->next;
	}
	return (newlist);
}
