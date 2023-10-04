/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_others_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:11:40 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/10/03 17:59:15 by dkurcbar         ###   ########.fr       */
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

char	**init_instruccion(void)
{
	char	**movs;
	int		i;

	i = -1;
	movs = ft_split("sa sb ss pa pb ra rb rr rra rrb rrr", ' ');
	return (movs);
}

void check_cmd(t_cmdlst **lst, t_stack **stack)
{
	char		**movs;
	int			flag;
	int			i;
	t_cmdlst	**firstcmd;

	firstcmd = lst;
	movs = init_instruccion();
	if (!movs)
		error_cmd(firstcmd, stack, NULL);
	i = -1;
	flag = 0;
	while (*lst)
	{
		while (i++ < 11)
		{
			if (!ft_strncmp(movs[i], (*lst)->cmd, ft_strlen((*lst)->cmd)))
				flag = 1;
		}
		if (flag == 0)
			error_cmd(firstcmd, stack, movs);
		flag = 0;
		*lst = (*lst)->next;
	}
}

