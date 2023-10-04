/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_calcs_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:13:18 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/10/03 13:17:52 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_mov	init_mov(void)
{
	t_mov	mov;

	mov.cost = 0;
	mov.pa = 0;
	mov.pb = 0;
	mov.ra = 0;
	mov.rb = 0;
	mov.rr = 0;
	return (mov);
}

t_mov	calc_mov_a_to_b(t_stack *first, t_stack *stack_a, t_stack *stack_b)
{
	t_info	info;
	t_mov	mov;
	int		pos;
	int		wtp;

	info = get_info(first, stack_b);
	pos = node_position(first, stack_a);
	mov = init_mov();
	if (pos > info.size_sa / 2)
		pos = -(info.size_sa - pos);
	mov.ra = pos;
	wtp = where_to_put_on_b((stack_a)->value, stack_b);
	if (wtp > info.size_sb / 2)
		wtp = -(info.size_sb - wtp);
	mov.rb = wtp;
	mov.pb = 1;
	mov = optimize_mov(mov);
	return (mov);
}

t_mov	calc_mov_b_to_a(t_stack *first, t_stack *stack_a, t_stack *stack_b)
{
	t_info	info;
	t_mov	mov;
	int		pos;
	int		wtp;

	info = get_info(stack_a, first);
	pos = node_position(stack_b, first);
	mov = init_mov();
	if (pos > info.size_sb / 2)
		pos = -(info.size_sb - pos);
	mov.rb = pos;
	wtp = where_to_put_on_a((stack_b)->value, stack_a);
	if (wtp > info.size_sa / 2)
		wtp = -(info.size_sa - wtp);
	mov.ra = wtp;
	mov.pa = 1;
	mov = optimize_mov(mov);
	return (mov);
}

void	calc_all_mov_a_to_b(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*first;

	first = stack_a;
	while (stack_a)
	{
		(stack_a)->movs = calc_mov_a_to_b(first, stack_a, stack_b);
		(stack_a) = (stack_a)->next;
	}
}

void	calc_all_mov_b_to_a(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*first;

	first = stack_b;
	while (stack_b)
	{
		(stack_b)->movs = calc_mov_b_to_a(first, stack_a, stack_b);
		(stack_b) = (stack_b)->next;
	}
}
