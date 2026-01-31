/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:50:27 by halragga          #+#    #+#             */
/*   Updated: 2026/01/31 12:49:41 by halragga         ###   ########.fr       */
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
void	free_stack(t_stack **stack);
// Parsing
void	parse_input(t_stack **stk, char *argv);
t_stack	*parser_main(int argc, char **argv);
long	ft_atol(const char *str);
int		parse_number(char *str);
t_stack	*create_node(int val);
void	add_to_stack(t_stack **stk, int val);

#endif
