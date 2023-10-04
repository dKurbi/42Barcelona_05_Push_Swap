/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_sort_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:25:03 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/10/03 13:26:55 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_rotating(t_stack **stack)
{
	int	rot;
	int	size;

	rot = is_rotate_a(*stack);
	size = ft_lstsize_ps(*stack);
	if ((rot != -1) && (rot <= size / 2))
	{
		while (rot--)
			ra(stack);
	}
	else if ((rot != -1) && (rot > size / 2))
	{
		rot = size - rot;
		while (rot--)
			rra(stack);
	}
}

void	sort_rotating_b(t_stack **stack)
{
	int	rot;
	int	size;

	rot = is_rotate_b(*stack);
	size = ft_lstsize_ps(*stack);
	if ((rot != -1) && (rot <= size / 2))
	{
		while (rot--)
			rb(stack);
	}
	else if ((rot != -1) && (rot > size / 2))
	{
		rot = size - rot;
		while (rot--)
			rrb(stack);
	}
}
