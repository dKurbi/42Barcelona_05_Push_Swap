/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_others.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:44:23 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/10/03 17:14:10 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(t_stack **stack)
{
	ft_lstclear_ps(stack);
	write(2, "Error\n", 6);
	exit (1);
}
