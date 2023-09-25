/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:18:14 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/09/23 16:27:32 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap_ps(t_list *lst, int(*f)(int, t_list*))
{
	t_list	*newlist;
	t_list	*nxt;
	t_list	*original;
	int		aux;
	

	original = lst;
	newlist = NULL;
	nxt = newlist;
	while (lst)
	{
		aux = f(lst->content, original);
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
