/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:20:27 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/10/04 15:49:28 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_b = NULL;
	stack_a = NULL;
	if (argc == 1)
		return (0);
	else if (argc == 2)
	{
		if (argv[1][0] == '\0')
			error(NULL);
		else
			create_stack(&stack_a, ft_split(argv[1], ' '));
	}
	else if (argc > 2)
		create_stack(&stack_a, &argv[1]);
	if (ft_lstsize_ps(stack_a) < 6)
		sort_small_stack(&stack_a, &stack_b);
	else if (ft_lstsize_ps(stack_a) > 5)
		sort_more_5(&stack_a, &stack_b);
	ft_lstclear_ps(&stack_a);
	ft_lstclear_ps(&stack_b);
	return (0);
}
