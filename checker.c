/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:26:48 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/10/03 18:02:50 by dkurcbar         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_cmdlst	*cmd_lst;
	t_cmdlst	*cmd;
	char		*arg;

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
	arg = get_next_line(0);
	while (arg && ft_strlen(arg) > 0)
	{
		if (arg)
		{
			cmd = new_cmd(arg);
			if (!cmd)
				error_cmd(&cmd_lst, &stack_a, NULL);
			cmd_add(&cmd_lst, cmd);
			free(arg);
		}
		arg = get_next_line(0);
	}
	check_cmd(&cmd_lst, &stack_a);
	print_lst(cmd_lst);
}