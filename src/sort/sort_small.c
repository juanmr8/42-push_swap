/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmora-ro <jmora-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 18:43:27 by jmora-ro          #+#    #+#             */
/*   Updated: 2025/11/14 15:06:30 by jmora-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sort_two(t_stack **a)
{
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

void	sort_three(t_stack **a)
{
	int	max;

	max = get_max(*a);
	if ((*a)->value == max)
	{
		ra(a);
		if (!is_sorted(*a))
			sa(a);
	}
	else if ((*a)->next->value == max)
	{
		rra(a);
		if (!is_sorted(*a))
			sa(a);
	}
	else
	{
		if ((*a)->value > (*a)->next->value)
			sa(a);
	}
}

void	push_min_to_b(t_stack **a, t_stack **b)
{
	int	min;
	int	pos;
	int	size;

	min = get_min(*a);
	pos = get_position(*a, min);
	size = stack_size(*a);
	if (pos <= (size / 2))
	{
		while ((*a)->value != min)
			ra(a);
	}
	else
	{
		while ((*a)->value != min)
			rra(a);
	}
	pb(a, b);
}

void	sort_five(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	if (size == 5)
	{
		push_min_to_b(a, b);
		push_min_to_b(a, b);
	}
	else if (size == 4)
	{
		push_min_to_b(a, b);
	}
	sort_three(a);
	while ((*b))
		pa(a, b);
}
