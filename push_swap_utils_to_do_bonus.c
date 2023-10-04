/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_to_do_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:36:24 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/10/04 15:47:19 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	if_is_swap_or_push(char *cmd, t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_strncmp(cmd, "sa\n", 2))
		sa_bonus(stack_a);
	else if (!ft_strncmp(cmd, "sb\n", 3))
		sb_bonus(stack_b);
	else if (!ft_strncmp(cmd, "ss\n", 3))
		ss_bonus(stack_a, stack_b);
	else if (!ft_strncmp(cmd, "pa\nn", 3))
		pa_bonus(stack_a, stack_b);
	else if (!ft_strncmp(cmd, "pb\n", 3))
		pb_bonus(stack_a, stack_b);
}

static void	if_is_rotate(char *cmd, t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_strncmp(cmd, "ra\n", 3))
		ra_bonus(stack_a);
	else if (!ft_strncmp(cmd, "rb\n", 3))
		rb_bonus(stack_b);
	else if (!ft_strncmp(cmd, "rr\n", 3))
		rr_bonus(stack_a, stack_b);
	else if (!ft_strncmp(cmd, "rra\n", 4))
		rra_bonus(stack_a);
	else if (!ft_strncmp(cmd, "rrb\n", 4))
		rrb_bonus(stack_b);
	else if (!ft_strncmp(cmd, "rrr\n", 4))
		rrr_bonus(stack_a, stack_b);
}

void	to_do_cmd_lst(t_cmdlst *clst, t_stack **stack_a, t_stack **stack_b)
{
	while (clst)
	{
		if_is_swap_or_push(clst->cmd, stack_a, stack_b);
		if_is_rotate(clst->cmd, stack_a, stack_b);
		clst = clst->next;
	}
}
