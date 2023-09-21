/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:31:54 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/09/21 17:44:41 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*nxt;
	t_list	*tmp;

	if (*lst == NULL)
		return ;
	tmp = *lst;
	nxt = (*lst)->next;
	while (nxt != NULL)
	{
		free(tmp);
		tmp = nxt;
		nxt = tmp->next;
	}
	free(tmp);
	*lst = NULL;
}
