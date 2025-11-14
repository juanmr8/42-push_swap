/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmora-ro <jmora-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 18:12:49 by jmora-ro          #+#    #+#             */
/*   Updated: 2025/11/14 17:08:22 by jmora-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "lib/libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_chunk
{
	int	min;
	int	max;
}	t_chunk;

long	ft_atol(char *str);
void	print_specific_error(char *error_msg);
int		*parse_input(int argc, char **argv);
void	validate_input(int argc, char **argv);
void	check_duplicates(int *numbers, int count);
int		is_valid_range(long num);
t_stack	*stack_new(int value);
t_stack	*stack_last(t_stack *stack);
t_stack	*array_to_stack(int *arr, int size);
void	free_stack(t_stack **stack);
int		is_sorted(t_stack *stack);
int		stack_size(t_stack *lst);
int		get_min(t_stack *stack);
int		get_max(t_stack *stack);
int		get_position(t_stack *stack, int value);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
int		stack_size(t_stack *stack);
void	sort_two(t_stack **a);
void	sort_three(t_stack **a);
void	push_min_to_b(t_stack **a, t_stack **b);
void	sort_five(t_stack **a, t_stack **b);
void	assign_indices(t_stack **stack_a);
int		has_elements_in_range(t_stack *stack, int min, int max);
int		calculate_chunk_count(int stack_size);
int		find_closest_in_range(t_stack *stack, int min, int max, int size);
void	push_chunks_to_b(t_stack **stack_a, t_stack **stack_b);
int		is_in_range(t_stack *stack, int min, int max);
int		should_rotate_up(int position, int stack_size);
int		find_max_index(t_stack *stack);
int		get_position_by_index(t_stack *stack, int target_index);
void	push_back_to_a(t_stack **stack_a, t_stack **stack_b);
void	sort_large(t_stack **stack_a, t_stack **stack_b);
#endif
