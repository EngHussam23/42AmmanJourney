/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:50:27 by halragga          #+#    #+#             */
/*   Updated: 2026/02/06 19:54:44 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* Standard Libraries */
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

/* User defined header */
# include "libft.h"

/* Data Structs */
// Stack node structure
typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

/* Functions prototypes */
// Error handling
void	ft_exit_error(int code);
// Validation & little helpers
int		is_space(char c);
int		is_sign(char c);
void	validate_args(int c, char **t);
void	check_dups(t_stack **stk);
int		is_sorted(t_stack *stack);
// Memory management
void	free_stack(t_stack **stack);
// Parsing
void	parse_input(t_stack **stk, char *argv);
t_stack	*parser_main(int argc, char **argv);
long	ft_atol(const char *str);
t_stack	*create_node(int val);
void	add_to_stack(t_stack **stk, int val);
// Swap OPs (for Radix sort)
void	swap_a_op(t_stack **stk_a);
void	push_to_a_op(t_stack **stk_a, t_stack **stk_b);
void	push_to_b_op(t_stack **stk_a, t_stack **stk_b);
void	rotate_a_op(t_stack **stk_a);
void	rev_rot_a(t_stack **stk_a);
// Indexing
int		get_stack_size(t_stack *stack);
void	give_index(t_stack *stack);
/* Radix sort */
// Small sorts
void	sort_stack(t_stack **stk_a, t_stack **stk_b);
// Main Raidix sort
void	radix_sort(t_stack **stk_a, t_stack **stk_b);

#endif
