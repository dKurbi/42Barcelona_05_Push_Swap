/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_push_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:21:13 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/10/04 14:57:03 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa_bonus(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
}

void	pb_bonus(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
}
