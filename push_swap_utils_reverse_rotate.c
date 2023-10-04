/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_reverse_rotate.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:23:28 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/10/03 13:21:12 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*tmp;
	int		size;

	size = ft_lstsize_ps(*stack);
	if (size > 1)
	{
		last = ft_lstlast_ps(*stack);
		ft_lstadd_front_ps(stack, last);
		tmp = (*stack);
		while (tmp->next != last)
			tmp = tmp->next;
		tmp->next = NULL;
	}
}

void	rra(t_stack **stack_a)
{
	ft_putstr("rra\n");
	reverse_rotate(stack_a);
}

void	rrb(t_stack **stack_b)
{
	ft_putstr("rrb\n");
	reverse_rotate(stack_b);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_putstr("rrr\n");
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}
