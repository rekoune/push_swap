/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arekoune <arekoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 01:33:55 by arekoune          #+#    #+#             */
/*   Updated: 2024/04/20 12:23:37 by arekoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*put_in_a(int ac, char **av)
{
	int		i;
	char	**str;
	int		j;
	t_list	*node;
	t_list	*head;

	head = NULL;
	i = 1;
	while (i < ac)
	{
		str = ft_split(av[i], ' ', &head);
		j = 0;
		while (str[j])
		{
			node = new_node(ft_atoi(str[j], &head, str));
			free(str[j]);
			add_back(&head, node);
			j++; 
		}
		free(str);
		i++;
	}
	return (head);
}

void	put_in_b(t_list **stack_a, t_list **stack_b)
{
	int	start;
	int	end;

	start = 0;
	end = 35;
	if (list_size(*stack_a) <= 100)
		end = 15;
	while (list_size(*stack_a))
	{
		if ((*stack_a)->index >= start && (*stack_a)->index <= end)
		{
			push(stack_b, stack_a, 'b', 1);
			start++;
			end++;
		}
		else if ((*stack_a)->index < start)
		{
			push(stack_b, stack_a, 'b', 1);
			rotate(stack_b, 'b', 1);
			start++;
			end++;
		}
		else if ((*stack_a)->index > end)
			rotate(stack_a, 'a', 1);
	}
}

void	sorting_a(t_list **stack_a, t_list **stack_b)
{
	int		max;
	int		size;
	t_list	*head;

	while (list_size(*stack_b))
	{
		size = list_size(*stack_b);
		head = *stack_b;
		max = max_index(*stack_b);
		if (head->index == max)
			push(stack_a, stack_b, 'a', 1);
		else if (position(head, max) > size / 2)
			reverse_rotate(stack_b, 'b', 1);
		else if (position(head, max) <= size / 2)
			rotate(stack_b, 'b', 1);
	}
}

void	ft_main(t_list **stack_a, t_list **stack_b)
{
	if (list_size(*stack_a) <= 3)
		sort_3(stack_a);
	else if (list_size(*stack_a) <= 5)
		sort_5(stack_a, stack_b);
	else
	{
		put_in_b(stack_a, stack_b);
		sorting_a(stack_a, stack_b);
	}
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		*array;

	stack_b = NULL;
	if (ac >= 2)
	{
		stack_a = put_in_a(ac, av);
		array = sort_array(stack_a);
		give_index(stack_a, array);
		free(array);
		if (repetation(stack_a) == 0)
			error(&stack_a, &stack_b, NULL, NULL);
		if (order_check(stack_a) != 0)
			ft_main(&stack_a, &stack_b);
		free_list(&stack_a);
	}
	return (0);
}
