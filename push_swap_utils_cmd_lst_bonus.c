/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_cmd_lst_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:33:45 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/10/04 15:50:17 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cmdlst	*new_cmd(char *value)
{
	t_cmdlst	*new;

	new = ft_calloc(1, sizeof(t_list));
	if (new != NULL)
	{
		new->cmd = ft_strdup(value);
		if (!new->cmd)
		{
			free (new);
			return (NULL);
		}
	}
	return (new);
}

void	cmd_add(t_cmdlst **lst, t_cmdlst *new)
{
	t_cmdlst	*last;

	if (new)
	{
		if (!*lst)
		{
			*lst = new;
			return ;
		}
		last = cmdlst_last (*lst);
		last->next = new;
	}
}

t_cmdlst	*cmdlst_last(t_cmdlst *lst)
{
	if (lst == NULL)
		return ((void *)0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	cmdlst_clear(t_cmdlst **lst)
{
	t_cmdlst	*nxt;
	t_cmdlst	*tmp;

	if (*lst == NULL)
		return ;
	tmp = *lst;
	nxt = (*lst)->next;
	while (nxt != NULL)
	{
		free(tmp->cmd);
		tmp->cmd = NULL;
		free(tmp);
		tmp = nxt;
		nxt = tmp->next;
	}
	free(tmp->cmd);
	free(tmp);
	*lst = NULL;
}
