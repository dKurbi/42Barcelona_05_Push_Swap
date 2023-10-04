/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:26:48 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/10/04 15:49:02 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_lst(t_cmdlst *lst)
{
	while (lst)
	{
		ft_printf("la lista contiene la instruccion %s", lst->cmd);
		lst = lst->next;
	}
}

void	print_stack(char *str, t_stack *stack)
{
	int	i;

	i = 0;
	ft_printf("%s\n", str);
	while (stack)
	{
		ft_printf("%d -> %d\n", i++, stack->value);
		stack = stack->next;
	}
}

static void	argc2(char **argv, t_stack **stack_a)
{
	if (argv[1][0] == '\0')
		error(NULL);
	else
		create_stack(stack_a, ft_split(argv[1], ' '));
}

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_cmdlst	*cmd_lst;
	t_info		info[2];

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	else if (argc == 2)
		argc2(argv, &stack_a);
	else if (argc > 2)
		create_stack(&stack_a, &argv[1]);
	info[0] = get_info(stack_a, NULL);
	get_str_cmd(&cmd_lst, &stack_a);
	check_cmd_lst(&cmd_lst, &stack_a);
	to_do_cmd_lst(cmd_lst, &stack_a, &stack_b);
	info[1] = get_info(stack_a, NULL);
	if (!(is_stack_sorted(stack_a)) && (info[0].size_sa == info[1].size_sa))
		ko_cmd(&cmd_lst, &stack_a, &stack_b);
	ok_exit(&cmd_lst, &stack_a, &stack_b);
}
