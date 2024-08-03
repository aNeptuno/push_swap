/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_checker.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 13:12:34 by adiban-i          #+#    #+#             */
/*   Updated: 2024/08/03 13:13:47 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_CHECKER_H
# define MY_CHECKER_H

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

#endif