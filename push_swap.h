/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:56:37 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/10/03 18:00:59 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ft_libft/libft.h"
# include "limits.h"

typedef struct s_mov
{
	int	rr;
	int	ra;
	int	rb;
	int	pa;
	int	pb;	
	int	cost;

}	t_mov;

typedef struct s_cmdlst
{
	char			*cmd;
	struct s_cmdlst	*next;
}	t_cmdlst;

typedef struct s_info
{
	int	size_sa;
	int	size_sb;
	int	min_a;
	int	min_b;
	int	max_a;
	int	max_b;
}	t_info;

typedef struct s_stack
{
	int				value;
	t_mov			movs;
	struct s_stack	*next;
}	t_stack;
int			arg_len(char **str);
int			check_arg(char **list_num_s);
int			check_max_int(int num, char *str);
void		calc_all_mov_a_to_b(t_stack *stack_a, t_stack *stack_b);
void		calc_all_mov_b_to_a(t_stack *stack_a, t_stack *stack_b);
t_mov		calc_mov_a_to_b(t_stack *first, t_stack *stack_a, t_stack *stack_b);
t_mov		calc_mov_b_to_a(t_stack *first, t_stack *stack_a, t_stack *stack_b);
t_info		get_info(t_stack *stack_a, t_stack *stack_b);
t_mov		get_cheaper(t_stack *stack);
int			get_index(int num, t_stack *lst);
int			get_max(t_stack *stack);
int			get_min(t_stack *stack);
void		create_stack(t_stack **stack_a, char **list_num_s);
void		do_movements(t_stack **stack_a, t_stack **stack_b, t_mov mov);
void		error(t_stack **stack);
void		free_split(char **split);
void		ft_lstdelone_ps(t_stack *lst);
void		ft_lstadd_back_ps(t_stack **lst, t_stack *new);
void		ft_lstadd_front_ps(t_stack **lst, t_stack *new);
void		ft_lstclear_ps(t_stack **lst);
t_stack		*ft_lstlast_ps(t_stack *lst);
t_stack		*ft_lstmap_ps(t_stack *lst, int (*f)(int, t_stack *));
t_stack		*ft_lstnew_ps(int value);
void		ft_lstdelone_ps(t_stack *lst);
int			ft_lstsize_ps(t_stack *lst);
int			ft_lstiter_ps(t_stack *lst, int (*f)(t_stack *));
int			is_exists(int num, t_stack *stack);
int			is_next_bigger(t_stack *lst);
int			is_next_smaller(t_stack *lst);
int			is_rotate_a(t_stack *lst);
int			is_rotate_b(t_stack *lst);
int			is_stack_sorted(t_stack *lst);
void		init_movs(t_mov *new_mov);
int			is_rotate_a(t_stack *lst);
int			is_rotate_b(t_stack *lst);
void		move_a_to_b(t_stack **stack_a, t_stack **stack_b);
void		move_b_to_a(t_stack **stack_a, t_stack **stack_b);
int			node_position(t_stack *first, t_stack *stack);
t_mov		optimize_mov(t_mov mov);
void		pa(t_stack **stack_a, t_stack **stack_b);
void		pb(t_stack **stack_a, t_stack **stack_b);
void		push(t_stack **stack_a, t_stack **stack_b);
void		ra(t_stack **stack_a);
void		rb(t_stack **stack_b);
void		reverse_rotate(t_stack **stack);
void		rra(t_stack **stack_a);
void		rrb(t_stack **stack_b);
void		rotate(t_stack **stack);
void		rr(t_stack **stack_a, t_stack **stack_b);
void		rra(t_stack **stack_a);
void		rrb(t_stack **stack_b);
void		rrr(t_stack **stack_a, t_stack **stack_b);
void		sa(t_stack **stack_a);
void		sb(t_stack **stack_b);
void		sort_3_elements(t_stack **stack);
void		sort_less_6(t_stack **stack_a, t_stack **stack_b);
void		sort_more_5(t_stack **stack_a, t_stack **stack_b);
void		sort_rotating(t_stack **stack);
void		sort_rotating_b(t_stack **stack);
void		sort_small_stack(t_stack **stack_a, t_stack **stack_b);
int			where_to_put_on_a(int n, t_stack *stack);
int			where_to_put_on_b(int n, t_stack *stack);
void		print_lst(t_cmdlst *lst);
t_cmdlst	*new_cmd(char *value);
void		cmd_add(t_cmdlst **lst, t_cmdlst *new);
t_cmdlst	*cmdlst_last(t_cmdlst *lst);
void		cmdlst_clear(t_cmdlst **lst);
void		error_cmd(t_cmdlst **lst, t_stack **stack, char **str);
char		**init_instruccion(void);
void	 	check_cmd(t_cmdlst **lst, t_stack **stack);

#endif
