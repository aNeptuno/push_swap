/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 17:20:15 by adiban-i          #+#    #+#             */
/*   Updated: 2024/07/28 13:12:47 by adiban-i         ###   ########.fr       */
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
}	t_node;

// Stack definition
typedef struct s_stack
{
	t_node	*top;
	int		size;
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

// Input validation
void	check_input(char	**args, int ac, t_program_data *pd);

// Stack operations
void	push(t_stack *stack, int data);
void	pop_first(t_stack *stack);

// Helper functions || temporal
void	print_stack(t_stack *s, char ch);
int		data_compare(t_node *node_n, t_node *node_m);

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

// Algorithm
void	small_sort(t_stack *stack_a, t_program_data *pd);
void	sort(t_stack *stack_a, t_stack *stack_b, t_program_data *pd);

#endif