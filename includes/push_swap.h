/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 17:20:15 by adiban-i          #+#    #+#             */
/*   Updated: 2024/08/01 13:53:21 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

// Node definition
typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
	struct s_node	*target;
	int				index;
	int				push_cost;
	int				cheapest;
}	t_node;

// Stack definition
typedef struct s_stack
{
	t_node	*top;
	int		size;
	int		median;
}	t_stack;

typedef struct s_program_data
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		valid_input;
	int		input_is_string;
}	t_program_data;

// Libft functions
int		ft_isdigit(int c);
void	ft_putstr(char *s);
int		ft_strlen(const char *str);
char	**ft_split(char const *s, char c);
long	ft_atoi(const char *str);
char	*ft_strchr(const char *s, int c);

// Free
void	free_data(t_program_data *prog_data);
void	free_args(char **args);

// Input validation
void	check_input(char	**args, int ac, t_program_data *pd);

// Stack operations
void	push(t_stack *stack, int data);
void	pop_first(t_stack *stack);

// Commands
void	pa(t_program_data *pd, int repeat);
void	pb(t_program_data *pd, int repeat);
void	sa(t_program_data *pd);
void	sb(t_program_data *pd);
void	ss(t_program_data *pd);
void	ra(t_program_data *pd);
void	rb(t_program_data *pd);
void	rr(t_program_data *pd);
void	rra(t_program_data *pd);
void	rrb(t_program_data *pd);
void	rrr(t_program_data *pd);

// Algorithm utils
void	print_stack(t_stack *s, char ch);
int		is_stack_sorted(t_stack *stack);

// Algorithm
t_node	*find_biggest(t_stack *stack);
t_node	*find_smallest(t_stack *stack);
void	small_sort(t_stack *stack_a, t_program_data *pd);
void	push_swap(t_stack *stack_a, t_stack *stack_b, t_program_data *pd);
void	set_indexes(t_stack *stack, int reset_target);
void	set_b_targets(t_node *node, t_stack *stack);
void	set_initial_data(t_stack *stack_a, t_stack *stack_b, int a);
void	rr_or_rrr_reset_index(t_stack *stack_a, t_stack *stack_b, t_program_data *pd, t_node *cheapest);

#endif