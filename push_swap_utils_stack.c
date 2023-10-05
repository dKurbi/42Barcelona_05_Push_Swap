/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_stack.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:43:55 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/10/05 15:27:47 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_stack(t_stack **stack_a, char **list_num_s, char **argv)
{
	int		i;
	t_stack	*new_node;
	t_stack	*lst_indexed;
	int		num;

	if (check_arg (list_num_s) == -1 || list_num_s == NULL)
		error(NULL);
	i = 0;
	while (list_num_s[i])
	{
		if (ft_strlen(list_num_s[i]) == 0)
			error(stack_a);
		num = ft_atoi(list_num_s[i]);
		if (check_max_int(num, list_num_s[i]) || is_exists(num, *stack_a) == -1)
			error(stack_a);
		new_node = ft_lstnew_ps(num);
		ft_lstadd_back_ps(stack_a, new_node);
		i++;
	}
	lst_indexed = ft_lstmap_ps(*stack_a, get_index);
	ft_lstclear_ps(stack_a);
	*stack_a = lst_indexed;
	free_split (list_num_s, argv);
}

void	ft_lstadd_front_ps(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	*lst = new;
}

void	ft_lstadd_back_ps(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (new)
	{
		if (!*lst)
		{
			*lst = new;
			return ;
		}
		last = ft_lstlast_ps (*lst);
		last->next = new;
	}
}

void	ft_lstclear_ps(t_stack **lst)
{
	t_stack	*nxt;
	t_stack	*tmp;

	if (lst == NULL || *lst == NULL)
		return ;
	tmp = *lst;
	nxt = (*lst)->next;
	while (nxt != NULL)
	{
		free(tmp);
		tmp = nxt;
		nxt = tmp->next;
	}
	free(tmp);
	*lst = NULL;
}

t_stack	*ft_lstmap_ps(t_stack *lst, int (*f)(int, t_stack*))
{
	t_stack	*newlist;
	t_stack	*nxt;
	t_stack	*original;
	int		aux;

	original = lst;
	newlist = NULL;
	nxt = newlist;
	while (lst)
	{
		aux = f(lst->value, original);
		nxt = ft_lstnew_ps(aux);
		if (!nxt)
		{
			ft_lstclear_ps(&newlist);
			return (NULL);
		}
		ft_lstadd_back_ps(&newlist, nxt);
		lst = lst->next;
	}
	return (newlist);
}
