/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_rotate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:22:36 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/10/03 13:21:46 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*tmp;

	if (ft_lstsize_ps(*stack) > 1)
	{
		first = (*stack);
		tmp = (*stack)->next;
		ft_lstadd_back_ps(stack, first);
		first->next = NULL;
		(*stack) = tmp;
	}
}

void	ra(t_stack **stack_a)
{
	ft_putstr("ra\n");
	rotate(stack_a);
}

void	rb(t_stack **stack_b)
{
	ft_putstr("rb\n");
	rotate(stack_b);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_putstr("rr\n");
	rotate(stack_a);
	rotate(stack_b);
}
