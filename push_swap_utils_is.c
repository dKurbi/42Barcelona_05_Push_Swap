/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_is.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:34:51 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/10/03 12:44:57 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_next_smaller(t_stack *lst)
{
	t_stack	*next;

	next = lst->next;
	if ((next) != NULL)
		if ((lst->value) > (next->value))
			return (1);
	return (0);
}

int	is_next_bigger(t_stack *lst)
{
	t_stack	*next;

	next = lst->next;
	if ((next) != NULL)
		if ((lst->value) < (next->value))
			return (1);
	return (0);
}

static t_stack	*init_v_is_r(int *r, int *s, t_stack *l, t_stack **l_i)
{
	*s = ft_lstsize_ps (l) - 1;
	*r = *s;
	*l_i = ft_lstmap_ps(l, get_index);
	return (*l_i);
}

int	is_rotate_a(t_stack *lst)
{
	int		rtn;
	int		flag;
	int		size;
	t_stack	*lst_index;
	t_stack	*lst_to_del;

	lst_index = NULL;
	flag = 2;
	lst_to_del = init_v_is_r(&rtn, &size, lst, &lst_index);
	while (lst_index->next && flag != 0)
	{
		if ((lst_index->next->value) - (lst_index->value) != 1)
		{
			flag--;
			rtn = size;
		}
		else
			rtn --;
		if (flag == 0)
			rtn = -1;
		else
			lst_index = lst_index -> next;
	}
	ft_lstclear_ps(&lst_to_del);
	return (rtn);
}

int	is_rotate_b(t_stack *lst)
{
	int		rtn;
	int		flag;
	int		size;
	t_stack	*lst_index;
	t_stack	*lst_to_del;

	lst_index = NULL;
	flag = 2;
	lst_to_del = init_v_is_r(&rtn, &size, lst, &lst_index);
	while (lst_index->next && flag != 0)
	{
		if ((lst_index->value) - (lst_index->next->value) != 1)
		{
			flag--;
			rtn = size;
		}
		else
			rtn --;
		if (flag == 0)
			rtn = -1;
		else
			lst_index = lst_index -> next;
	}
	ft_lstclear_ps(&lst_to_del);
	return (rtn);
}
