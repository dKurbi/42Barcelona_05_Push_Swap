/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:20:27 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/09/21 18:03:50 by dkurcbar         ###   ########.fr       */
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

int	isexists(int num, t_list *stack)
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
int position(int num, t_list *lst)
{
	int		order;
	t_list	*next;

	next = lst;
	order = 0; 
	while (next)
	{
		if (num > next->content)
		{
			order++;
		}
		next = next->next;
	}
	return (order);
}

int	create_stack(t_list **stack, char **list_num_s)
{
	int		i;
	t_list	*new;
	t_list	*next;
	t_list	*order;
	int		num;

	if (check_arg (list_num_s) == -1)
		return (-1);
	i = 0;
	while (list_num_s[i])
	{
		num = ft_atoi(list_num_s[i]);
		if (check_max_int(num, list_num_s[i]) || isexists(num, *stack) == -1)
			return (-1);
		new = ft_lstnew(num);
		ft_lstadd_back(stack, new);
		i++;
	}
	order = ft_lstmap(*stack, position);
	next = *stack;
	while (next)
	{
		ft_printf("%d\n", next->content);
		next = next->next;
	}
	next = order;
	while (next)
	{
		ft_printf("%d\n", next->content);
		next = next->next;
	}
	return (0);
}



int	main(int argc, char **argv)
{
	t_list	*stack_a;
	//t_list	*stack_b;
	char	**list_num_s;


	list_num_s = ft_split(argv[1], ' ');
	if (argc == 1)
		return (0);
	if (create_stack(&stack_a, list_num_s) == -1)
	{
		ft_lstclear(&stack_a);
		free_split(list_num_s);
		ft_printf("error\n");
		return (0);
	}
	ft_lstclear(&stack_a);
	free_split(list_num_s);
	return (0);
}