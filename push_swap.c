/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:20:27 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/09/23 20:12:13 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft/libft.h"

int	long_arg(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}


int	check_max_int(int num, char *str)
{
	char	*max;
	char	*min;
	int		i;

	i = -1;
	max = "2147483647\0";
	min = "-2147483648\0";
	if (num == 2147483647)
	{
		while (max[++i] != '\0')
		{
			if (max[i] != str[i] || ft_strlen (str) > 10)
				return (1);
		}
	}
	i = -1;
	if (num == -2147483648)
	{
		while (min[++i] != '\0')
		{
			if (min[i] != str[i] || ft_strlen (str) > 11)
				return (1);
		}
	}
	return (0);
}

int	check_arg(char **list_num_s)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (list_num_s[i])
	{
		j = 0;
		while (list_num_s[i][j] != '\0')
		{
			c = list_num_s[i][j];
			if (!ft_isdigit(c))
			{
				if (!((c == '-' || c == '+') && j == 0))
					return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	is_exists(int num, t_list *stack)
{
	t_list	*next;

	next = stack;
	while (next)
	{
		if (next->content == num)
			return (-1);
		next = next->next;
	}
	return (0);
}

void free_split(char **split)
{
	int i;

	i = 0;
	if (split != NULL)
	{
		while (split[i])
		{
			free (split[i]);
			i++;
		}
		free (split);
	}
}
int get_index(int num, t_list *lst)
{
	int		index;
	t_list	*next;

	next = lst;
	index = 0; 
	while (next)
	{
		if (num > next->content)
		{
			index++;
		}
		next = next->next;
	}
	return (index);
}
int is_next_smaller(t_list *lst)
{
	t_list	*next;

	next = lst->next;
	if ((next) != NULL)
		if ((lst->content) > (next->content))
			return (1);
	return (0);
}
int is_stack_sorted(t_list *lst)
{
	if  (ft_lstiter_ps(lst, is_next_smaller))
		return (0);
	return (1);
}

void print_lst(char *str, t_list *lst)
{
	ft_putstr(str);
	while (lst)
	{
		ft_printf("%d\n", lst->content);
		lst = lst->next;
	}
}

int	create_stack(t_list **stack, char **list_num_s)
{
	int		i;
	t_list	*new_node;
	t_list	*lst_indexed;
	int		num;

	if (check_arg (list_num_s) == -1)
		return (-1);
	i = 0;
	while (list_num_s[i])
	{
		num = ft_atoi(list_num_s[i]);
		if (check_max_int(num, list_num_s[i]) || is_exists(num, *stack) == -1)
			return (-1);
		new_node = ft_lstnew(num);
		ft_lstadd_back(stack, new_node);
		i++;
	}
	lst_indexed = ft_lstmap_ps(*stack, get_index);
	ft_lstclear(stack);
	*stack = lst_indexed;
	return (0);
}
void swap_stack(t_list **stack)
{
	t_list	*first;
	t_list 	*second;
	t_list	*third;

	if (ft_lstsize(*stack) > 1)
	{
		first = (*stack);
		second = (*stack)-> next;
		third = (*stack) -> next ->next;
		*stack = second;
		(*stack)-> next = first;
		(*stack) -> next -> next = third;
	}

}

void sa(t_list **stack_a)
{
	ft_putstr("sa\n");
	swap_stack(stack_a);
}
void sb(t_list **stack_b)
{
	ft_putstr("sb\n");
	swap_stack(stack_b);
}
void ss(t_list **stack_a, t_list **stack_b)
{
	ft_putstr("ss\n");
	swap_stack(stack_a);
	swap_stack(stack_b);
}

void push(t_list **stack_a, t_list **stack_b)
{
	t_list	*first_a;
	t_list	*first_b;
	
	first_b = (*stack_b) ->next;
	first_a = (*stack_b);
	ft_lstadd_front(stack_a, first_a);
	*stack_b = first_b;
}
void pa(t_list **stack_a, t_list **stack_b)
{
	
	ft_putstr("pa\n");
	push(stack_a, stack_b);
}
void pb(t_list **stack_a, t_list **stack_b)
{
	
	ft_putstr("pb\n");
	push(stack_b, stack_a);
}

void rotate(t_list **stack)
{
	t_list *first;
	t_list *tmp;

	if (ft_lstsize(*stack) > 1)
	{
		first = (*stack);
		tmp = (*stack) ->next;
		ft_lstadd_back(stack, first);
		first->next = NULL;
		(*stack) = tmp;
	}
}


void reverse_rotate(t_list **stack)
{
	t_list	*last;
	t_list	*first;
	t_list	*tmp; 
	int		size;

	size = ft_lstsize(*stack);
	if (size > 1)
	{
		last = ft_lstlast(*stack);
		first = (*stack) ->next;
		ft_lstadd_front(stack, last);
		tmp = (*stack);
		while (tmp->next != last)
			tmp = tmp->next;
		tmp->next = NULL;
	}
}

void ra(t_list **stack_a)
{
	ft_putstr("ra\n");
	rotate(stack_a);
}
void rb(t_list **stack_b)
{
	ft_putstr("rb\n");
	rotate(stack_b);
}
void rr(t_list **stack_a, t_list **stack_b)
{
	ft_putstr("rr\n");
	rotate(stack_a);
	rotate(stack_b);
}
void rra(t_list **stack_a)
{
	ft_putstr("rra\n");
	reverse_rotate(stack_a);
}
void rrb(t_list **stack_b)
{
	ft_putstr("rrb\n");
	reverse_rotate(stack_b);
}
void rrr(t_list **stack_a, t_list **stack_b)
{
	ft_putstr("rrr\n");
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}



int	main(int argc, char **argv)
{
	t_list	*stack_a;
	//t_list	*stack_b;
	int		rtn;

	rtn = 0;
	if (argc == 1)
		return (0);
	else if (argc == 2)
		rtn = create_stack(&stack_a,ft_split(argv[1], ' '));
	else if (argc > 2)
		rtn = create_stack(&stack_a, &argv[1]);
	if (rtn == -1)
	{
		ft_lstclear(&stack_a);
		ft_printf("error\n");
		return (0);
	}
	
	
	
	print_lst("stack a\n", stack_a);
	rra(&stack_a);
	rra(&stack_a);
	print_lst("stack a\n", stack_a);
	
	/*pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	print_lst("stack a\n", stack_a);
	print_lst("stack b\n", stack_b);
	ra(&stack_a);
	print_lst("stack a\n", stack_a);
	rb(&stack_b);
	print_lst("stack b\n", stack_b);
	rr(&stack_a, &stack_b);
	print_lst("stack a\n", stack_a);
	print_lst("stack b\n", stack_b);
	
	rrr(&stack_a, &stack_b);
	print_lst("stack a\n", stack_a);
	print_lst("stack b\n", stack_b);
	
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);*/
	
	return (0);
}