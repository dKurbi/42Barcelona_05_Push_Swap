/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_to_move_2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:43:57 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/10/03 13:48:30 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_rr(t_stack **stack_a, t_stack **stack_b, t_mov mov)
{
	if (mov.rr < 0)
	{
		mov.rr = ft_abs(mov.rr);
		while (mov.rr--)
			rrr (stack_a, stack_b);
	}
	else if (mov.rr > 0)
	{
		while (mov.rr--)
			rr(stack_a, stack_b);
	}
}

static void	do_ra(t_stack **stack_a, t_mov mov)
{
	if (mov.ra < 0)
	{
		mov.ra = ft_abs(mov.ra);
		while (mov.ra--)
			rra (stack_a);
	}
	else if (mov.ra > 0)
	{
		while (mov.ra--)
			ra(stack_a);
	}
}

static void	do_rb(t_stack **stack_b, t_mov mov)
{
	if (mov.rb < 0)
	{
		mov.rb = ft_abs(mov.rb);
		while (mov.rb--)
			rrb (stack_b);
	}
	else if (mov.rb > 0)
	{
		while (mov.rb--)
			rb(stack_b);
	}
}

void	do_movements(t_stack **stack_a, t_stack **stack_b, t_mov mov)
{
	do_rr(stack_a, stack_b, mov);
	do_ra(stack_a, mov);
	do_rb(stack_b, mov);
	while (mov.pa--)
		pa(stack_a, stack_b);
	while (mov.pb--)
		pb(stack_a, stack_b);
}
