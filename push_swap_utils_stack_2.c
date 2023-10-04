/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_stack_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:47:37 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/10/03 13:47:48 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstiter_ps(t_stack *lst, int (*f)(t_stack*))
{
	while (lst)
	{
		if (f(lst) == 1)
			return (1);
		lst = lst->next;
	}
	return (0);
}

t_stack	*ft_lstnew_ps(int value)
{
	t_stack	*new;

	new = ft_calloc(1, sizeof(t_stack));
	if (new != NULL)
		new->value = value;
	return (new);
}

t_stack	*ft_lstlast_ps(t_stack *lst)
{
	if (lst == NULL)
		return ((void *)0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	ft_lstsize_ps(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int	node_position(t_stack *first, t_stack *stack)
{
	int	i;
	int	len;

	len = ft_lstsize_ps(first);
	i = 0;
	while (len-- > 0 && first)
	{
		if (stack == first)
			return (i);
		i++;
		first = first->next;
	}
	return (-1);
}
