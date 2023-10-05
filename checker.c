/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:26:48 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/10/05 17:57:26 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	argc2(char **argv, t_stack **stack_a, char **argv2)
{
	if (argv[1][0] == '\0')
		error(NULL);
	else
		create_stack(stack_a, ft_split(argv[1], ' '), argv2);
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
		argc2(argv, &stack_a, &argv[1]);
	else if (argc > 2)
		create_stack(&stack_a, &argv[1], &argv[1]);
	info[0] = get_info(stack_a, NULL);
	get_str_cmd(&cmd_lst, &stack_a);
	check_cmd_lst(&cmd_lst, &stack_a);
	to_do_cmd_lst(cmd_lst, &stack_a, &stack_b);
	info[1] = get_info(stack_a, NULL);
	if ((is_stack_sorted(stack_a) == 0) || (info[0].size_sa != info[1].size_sa))
		ko_cmd(&cmd_lst, &stack_a, &stack_b);
	ok_exit(&cmd_lst, &stack_a, &stack_b);
}
