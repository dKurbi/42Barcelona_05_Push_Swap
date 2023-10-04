/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_sort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:07:45 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/10/03 13:25:32 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_less_6(t_stack **stack_a, t_stack **stack_b)
{
	int	len;

	len = ft_lstsize_ps(*stack_a);
	while (len-- > 3)
	{
		pb(stack_a, stack_b);
	}
	sort_3_elements(stack_a);
	move_b_to_a(stack_a, stack_b);
	sort_rotating(stack_a);
}

void	sort_more_5(t_stack **stack_a, t_stack **stack_b)
{
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	if (is_rotate_b(*stack_b) == -1)
		sort_rotating_b (stack_b);
	move_a_to_b(stack_a, stack_b);
	move_b_to_a(stack_a, stack_b);
}

void	sort_small_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	len;

	(void) stack_b;
	len = ft_lstsize_ps (*stack_a);
	if (is_rotate_a(*stack_a) != -1)
		sort_rotating(stack_a);
	else if (len < 6)
		sort_less_6(stack_a, stack_b);
}

void	sort_3_elements(t_stack **stack)
{
	if (is_rotate_a(*stack) == -1)
		sa(stack);
	sort_rotating(stack);
}
