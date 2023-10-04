/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_reverse_rotate_bonus.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:23:28 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/10/04 15:05:53 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra_bonus(t_stack **stack_a)
{
	reverse_rotate(stack_a);
}

void	rrb_bonus(t_stack **stack_b)
{
	reverse_rotate(stack_b);
}

void	rrr_bonus(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}
