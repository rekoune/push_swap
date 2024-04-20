/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arekoune <arekoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 21:44:38 by arekoune          #+#    #+#             */
/*   Updated: 2024/04/20 12:23:30 by arekoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	rule_check(char *line)
{
	if (compare("sa\n", line) == 0 || compare("sb\n", line) == 0
		|| compare("ss\n", line) == 0 || compare("pa\n", line) == 0
		|| compare("pb\n", line) == 0 || compare("ra\n", line) == 0
		|| compare("rb\n", line) == 0 || compare("rr\n", line) == 0
		|| compare("rra\n", line) == 0 || compare("rrb\n", line) == 0
		|| compare("rrr\n", line) == 0)
		return (1);
	return (0);
}

void	do_the_rule(t_list **stack_a, t_list **stack_b, char *line)
{
	if (compare("sa\n", line) == 0)
		swap(stack_a, 'a', 0);
	else if (compare("sb\n", line) == 0)
		swap(stack_b, 'b', 0);
	else if (compare("ss\n", line) == 0)
		swap_a_b(stack_a, stack_b, 0);
	else if (compare("pa\n", line) == 0)
		push(stack_a, stack_b, 'a', 0);
	else if (compare("pb\n", line) == 0)
		push(stack_b, stack_a, 'b', 0);
	else if (compare("ra\n", line) == 0)
		rotate(stack_a, 'a', 0);
	else if (compare("rb\n", line) == 0)
		rotate(stack_b, 'b', 0);
	else if (compare("rr\n", line) == 0)
		rotate_a_b(stack_a, stack_b, 0);
	else if (compare("rra\n", line) == 0)
		reverse_rotate(stack_a, 'a', 0);
	else if (compare("rrb\n", line) == 0)
		reverse_rotate(stack_b, 'b', 0);
	else if (compare("rrr\n", line) == 0)
		reverse_rotate_all(stack_a, stack_b, 0);
}

void	get_the_line(t_list **stack_a, t_list **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (rule_check(line) == 0)
			error(stack_a, stack_b, NULL, NULL);
		do_the_rule(stack_a, stack_b, line);
		free(line);
		line = get_next_line(0);
	}
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_b = NULL;
	if (ac >= 2)
	{
		stack_a = put_in_a_bonus(ac, av);
		if (repetation(stack_a) == 0)
			error(&stack_a, &stack_b, NULL, NULL);
		get_the_line(&stack_a, &stack_b);
		if ((list_size(stack_b) == 0 && order_check(stack_a) == 0)
			|| list_size(stack_a) == 1)
			printf("OK\n");
		else
			printf("KO\n");
		free_list(&stack_a);
	}
}
