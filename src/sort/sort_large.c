/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmora-ro <jmora-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 19:29:40 by jmora-ro          #+#    #+#             */
/*   Updated: 2025/11/14 15:05:00 by jmora-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	process_chunk_element(t_stack **stack_a, t_stack **stack_b,
	t_chunk chunk, int size)
{
	int	chunk_mid;
	int	pos;

	if (is_in_range(*stack_a, chunk.min, chunk.max))
	{
		pb(stack_a, stack_b);
		chunk_mid = (chunk.min + chunk.max) / 2;
		if ((*stack_b)->index < chunk_mid)
			rb(stack_b);
	}
	else
	{
		pos = find_closest_in_range(*stack_a, chunk.min, chunk.max, size);
		if (pos <= size / 2)
		{
			while (!is_in_range(*stack_a, chunk.min, chunk.max))
				ra(stack_a);
		}
		else
		{
			while (!is_in_range(*stack_a, chunk.min, chunk.max))
				rra(stack_a);
		}
	}
}

void	push_chunks_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int		chunk_count;
	int		size;
	int		i;
	t_chunk	chunk;

	size = stack_size(*stack_a);
	chunk_count = calculate_chunk_count(size);
	i = 0;
	while (i < chunk_count)
	{
		chunk.min = (size * i) / chunk_count;
		chunk.max = (size * (i + 1)) / chunk_count - 1;
		while (has_elements_in_range(*stack_a, chunk.min, chunk.max))
			process_chunk_element(stack_a, stack_b, chunk, size);
		i++;
	}
}

void	push_back_to_a(t_stack **stack_a, t_stack **stack_b)
{
	int	max_index;
	int	max_pos;
	int	size;

	size = stack_size(*stack_b);
	while (*stack_b)
	{
		max_index = find_max_index(*stack_b);
		max_pos = get_position_by_index(*stack_b, max_index);
		if (max_pos <= size / 2)
		{
			while ((*stack_b)->index != max_index)
				rb(stack_b);
		}
		else
		{
			while ((*stack_b)->index != max_index)
				rrb(stack_b);
		}
		pa(stack_a, stack_b);
		size--;
	}
}

void	sort_large(t_stack **stack_a, t_stack **stack_b)
{
	assign_indices(stack_a);
	push_chunks_to_b(stack_a, stack_b);
	push_back_to_a(stack_a, stack_b);
}
