/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_push.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:21:13 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/10/03 13:20:43 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*first_a;
	t_stack	*first_b;

	first_b = (*stack_b)->next;
	first_a = (*stack_b);
	ft_lstadd_front_ps(stack_a, first_a);
	*stack_b = first_b;
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	ft_putstr("pa\n");
	push(stack_a, stack_b);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	ft_putstr("pb\n");
	push(stack_b, stack_a);
}
