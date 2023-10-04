/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_swap.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:19:15 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/10/03 13:29:32 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if (ft_lstsize_ps(*stack) > 1)
	{
		first = (*stack);
		second = (*stack)-> next;
		third = (*stack)-> next-> next;
		*stack = second;
		(*stack)-> next = first;
		(*stack)-> next -> next = third;
	}
}

void	sa(t_stack **stack_a)
{
	ft_putstr("sa\n");
	swap_stack(stack_a);
}

void	sb(t_stack **stack_b)
{
	ft_putstr("sb\n");
	swap_stack(stack_b);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_putstr("ss\n");
	swap_stack(stack_a);
	swap_stack(stack_b);
}
