/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_others_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:11:40 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/10/04 16:36:23 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_cmd(t_cmdlst **lst, t_stack **stack, char **str)
{
	free_split(str);
	cmdlst_clear(lst);
	ft_lstclear_ps(stack);
	write(2, "Error\n", 6);
	exit (1);
}

void	ok_exit(t_cmdlst **lst, t_stack **stack_a, t_stack **stack_b)
{
	cmdlst_clear(lst);
	ft_lstclear_ps(stack_a);
	ft_lstclear_ps(stack_b);
	ft_putstr("OK\n");
	exit (0);
}

void	ko_cmd(t_cmdlst **lst, t_stack **stack_a, t_stack **stack_b)
{
	cmdlst_clear(lst);
	ft_lstclear_ps(stack_a);
	ft_lstclear_ps(stack_b);
	write(2, "KO\n", 3);
	exit (1);
}

char	**init_instruccion(t_cmdlst **lst, t_stack **stack)
{
	char	**movs;
	int		i;
	char	*str;

	i = -1;
	str = "sa\n sb\n ss\n pa\n pb\n ra\n rb\n rr\n rra\n rrb\n rrr\n \n";
	if (str == NULL)
		return (NULL);
	movs = ft_split(str, ' ');
	if (!movs)
		error_cmd(lst, stack, NULL);
	return (movs);
}

void	check_cmd_lst(t_cmdlst **lst, t_stack **stack)
{
	char		**movs;
	int			flag;
	int			i;
	int			j;
	t_cmdlst	*cmdlst;

	cmdlst = *lst;
	movs = init_instruccion(lst, stack);
	i = 12;
	j = 0;
	flag = 0;
	while (cmdlst)
	{
		while (i-- && flag == 0)
		{
			if (!ft_strncmp(movs[i], cmdlst->cmd, ft_strlen(cmdlst->cmd)))
				flag = 1;
		}
		i = 12;
		if (flag == 0)
			error_cmd(lst, stack, movs);
		flag = 0;
		cmdlst = cmdlst->next;
	}
	free_split(movs);
}
