/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_ps_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:55:44 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/09/23 16:46:25 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstiter_ps(t_list *lst, int (*f)(t_list*))
{
	while (lst)
	{
		if (f(lst) == 1)
			return (1);
		lst = lst->next;
	}
	return(0);
}
