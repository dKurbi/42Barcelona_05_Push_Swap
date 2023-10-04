/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_calcs.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:09:50 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/10/03 13:16:43 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	where_to_put_on_a(int n, t_stack *stack)
{
	int		i;
	t_info	info;

	if (!stack)
		return (0);
	info = get_info(stack, NULL);
	if (n < info.min_a || n > info.max_a)
		return (is_rotate_a(stack));
	i = 1;
	if (n < stack->value && n > ft_lstlast_ps(stack)->value)
		return (0);
	if (stack)
	{
		while (stack->next)
		{
			if (stack->value < n && stack->next->value > n)
				return (i);
			i++;
			stack = stack->next;
		}
	}
	return (i);
}

int	where_to_put_on_b(int n, t_stack *stack)
{
	int		i;
	t_info	info;

	if (!stack)
		return (0);
	info = get_info(NULL, stack);
	if (n < info.min_b || n > info.max_b)
		return (is_rotate_b(stack));
	i = 1;
	if (n > stack->value && n < ft_lstlast_ps(stack)->value)
		return (0);
	if (stack)
	{
		while (stack->next)
		{
			if (stack->value > n && stack->next->value < n)
				return (i);
			i++;
			stack = stack->next;
		}
	}
	return (i);
}

int	calc_cost(t_mov mov)
{
	int	cost;

	cost = ft_abs(mov.pa) + ft_abs(mov.pb) + ft_abs(mov.ra) + ft_abs(mov.rb);
	cost += ft_abs(mov.rr);
	return (cost);
}

static void	is_both_positive(t_mov *mov)
{
	if ((*mov).ra > (*mov).rb)
	{
		(*mov).rr = (*mov).rb;
		(*mov).ra = (*mov).ra - (*mov).rb;
		(*mov).rb = 0;
	}
	else if ((*mov).rb > (*mov).ra)
	{
		(*mov).rr = (*mov).ra;
		(*mov).rb = (*mov).rb - (*mov).ra;
		(*mov).ra = 0;
	}
}

t_mov	optimize_mov(t_mov mov)
{
	if ((mov.ra > 0) && (mov.rb > 0))
		is_both_positive(&mov);
	else if ((mov.ra < 0) && (mov.rb < 0))
	{
		if (mov.ra < mov.rb)
		{
			mov.rr = mov.rb;
			mov.ra = mov.ra - mov.rb;
			mov.rb = 0;
		}
		else if (mov.rb < mov.ra)
		{
			mov.rr = mov.ra;
			mov.rb = mov.rb - mov.ra;
			mov.ra = 0;
		}
	}
	mov.cost = calc_cost(mov);
	return (mov);
}
