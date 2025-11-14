/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmora-ro <jmora-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:24:31 by jmora-ro          #+#    #+#             */
/*   Updated: 2025/11/14 12:22:35 by jmora-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	has_elements_in_range(t_stack *stack, int min, int max)
{
	while (stack)
	{
		if (is_in_range(stack, min, max))
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	is_in_range(t_stack *stack, int min, int max)
{
	return (stack->index >= min && stack->index <= max);
}

int	calculate_chunk_count(int stack_size)
{
	if (stack_size <= 100)
		return (4);
	else if (stack_size <= 500)
		return (11);
	else
		return (stack_size / 50);
}

static void	evaluate_closest(int position, int size,
	int *closest_pos, int *min_distance)
{
	int	distance;

	if (position <= size / 2)
		distance = position;
	else
		distance = size - position;
	if (distance < *min_distance)
	{
		*min_distance = distance;
		*closest_pos = position;
	}
}

int	find_closest_in_range(t_stack *stack, int min, int max, int size)
{
	int	position;
	int	closest_pos;
	int	min_distance;

	position = 0;
	closest_pos = -1;
	min_distance = size + 1;
	while (stack)
	{
		if (is_in_range(stack, min, max))
			evaluate_closest(position, size, &closest_pos, &min_distance);
		position++;
		stack = stack->next;
	}
	return (closest_pos);
}
