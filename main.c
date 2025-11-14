/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmora-ro <jmora-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 11:27:55 by jmora-ro          #+#    #+#             */
/*   Updated: 2025/11/14 16:42:15 by jmora-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_split_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
}

static int	*init_numbers(int argc, char **argv, int *count)
{
	int		*numbers;
	char	**args;

	args = NULL;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		*count = 0;
		while (args[*count])
			(*count)++;
		validate_input(*count, args);
		numbers = parse_input(*count, args);
		check_duplicates(numbers, *count);
		free_split_args(args);
	}
	else
	{
		*count = argc - 1;
		validate_input(*count, &argv[1]);
		numbers = parse_input(*count, &argv[1]);
		check_duplicates(numbers, *count);
	}
	if (!numbers)
		return (NULL);
	return (numbers);
}

static t_stack	*init_stack(int *numbers, int count)
{
	t_stack	*stack;

	stack = array_to_stack(numbers, count);
	if (!stack)
	{
		free(numbers);
		print_specific_error("Memory allocation failed");
	}
	return (stack);
}

static void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = stack_size(*stack_a);
	if (size == 2)
		sort_two(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size <= 5)
		sort_five(stack_a, stack_b);
	else
		sort_large(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	int		*numbers;
	int		count;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	numbers = init_numbers(argc, argv, &count);
	stack_a = init_stack(numbers, count);
	stack_b = NULL;
	free(numbers);
	push_swap(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
