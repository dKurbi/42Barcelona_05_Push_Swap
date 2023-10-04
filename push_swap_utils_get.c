/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_get.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:19:50 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/10/03 12:40:59 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max(t_stack *stack)
{
	int	max;

	max = INT_MIN;
	while (stack)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

int	get_min(t_stack *stack)
{
	int	min;

	min = INT_MAX;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

t_info	get_info(t_stack *stack_a, t_stack *stack_b)
{
	t_info	info;

	if (stack_a)
	{
		info.size_sa = ft_lstsize_ps (stack_a);
		info.min_a = get_min(stack_a);
		info.max_a = get_max(stack_a);
	}
	if (stack_b)
	{
		info.size_sb = ft_lstsize_ps (stack_b);
		info.min_b = get_min(stack_b);
		info.max_b = get_max(stack_b);
	}
	return (info);
}

int	get_index(int num, t_stack *lst)
{
	int		index;
	t_stack	*next;

	next = lst;
	index = 0;
	while (next)
	{
		if (num > next->value)
		{
			index++;
		}
		next = next->next;
	}
	return (index);
}

t_mov	get_cheaper(t_stack *stack)
{
	t_mov	cheaper;

	cheaper = stack->movs;
	while (stack)
	{
		if (stack->movs.cost < cheaper.cost)
			cheaper = stack->movs;
		stack = stack ->next;
	}
	return (cheaper);
}
