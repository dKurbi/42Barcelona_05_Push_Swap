/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_get_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:30:25 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/10/04 15:50:33 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_str_cmd(t_cmdlst **cmd_lst, t_stack **stack_a)
{
	char		*str_cmd;
	t_cmdlst	*cmd;

	str_cmd = get_next_line(0);
	while (str_cmd && ft_strncmp(str_cmd, "\n", ft_strlen(str_cmd)))
	{
		if (str_cmd)
		{
			cmd = new_cmd(str_cmd);
			if (!cmd)
				error_cmd(cmd_lst, stack_a, NULL);
			cmd_add(cmd_lst, cmd);
			free(str_cmd);
		}
		str_cmd = get_next_line(0);
	}
}
