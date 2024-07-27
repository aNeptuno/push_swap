/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 17:20:15 by adiban-i          #+#    #+#             */
/*   Updated: 2024/07/27 15:55:21 by adiban-i         ###   ########.fr       */
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
}	t_node;

// Stack definition
typedef struct s_stack
{
	t_node	*top;
}	t_stack;

typedef struct s_program_data
{
    t_stack *stack_a;
    t_stack *stack_b;
    int     valid_input;
    int     input_is_string;
}   t_program_data;

// Libft functions
int		ft_isdigit(int c);
void	ft_putstr(char *s);
int		ft_strlen(const char *str);
char	**ft_split(char const *s, char c);
long	ft_atoi(const char *str);
char	*ft_strchr(const char *s, int c);

// Free
void free_data(t_program_data *prog_data);

// Input validation
void	check_input(char	**args, int ac, t_program_data *pd);

// Stack operations
void	push(t_stack* stack, int data);

// Helper functions || temporal
void print_stack(t_stack *s);

#endif