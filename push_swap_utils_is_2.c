/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_is_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:36:11 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/10/03 12:40:12 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_exists(int num, t_stack *stack)
{
	t_stack	*next;

	next = stack;
	while (next)
	{
		if (next->value == num)
			return (-1);
		next = next->next;
	}
	return (0);
}

int	is_stack_sorted(t_stack *lst)
{
	if (ft_lstiter_ps(lst, is_next_smaller))
		return (0);
	return (1);
}
