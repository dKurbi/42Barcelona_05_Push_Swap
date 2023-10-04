/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_to_move.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:54:19 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/10/03 13:47:17 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	t_mov	cheaper;

	if (ft_lstsize_ps(*stack_a) == 0 && is_rotate_b(*stack_b))
	{
		sort_rotating_b(stack_b);
		while (*stack_b)
			pa(stack_a, stack_b);
	}
	else
	{
		while (*stack_b)
		{
			calc_all_mov_b_to_a(*stack_a, *stack_b);
			cheaper = get_cheaper(*stack_b);
			do_movements(stack_a, stack_b, cheaper);
		}
	}
}

void	move_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_mov	cheaper;

	while (*stack_a)
	{
		calc_all_mov_a_to_b(*stack_a, *stack_b);
		cheaper = get_cheaper(*stack_a);
		do_movements(stack_a, stack_b, cheaper);
	}
}
