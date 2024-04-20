/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arekoune <arekoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:40:40 by arekoune          #+#    #+#             */
/*   Updated: 2024/04/20 12:59:55 by arekoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	array_swap(int *array, int i)
{
	int	k;
	int	j;
	int	tmp;

	j = 0;
	tmp = 0;
	while (j < i)
	{
		k = 0;
		while (k < i - j - 1)
		{
			if (array[k] > array[k + 1])
			{
				tmp = array[k];
				array[k] = array[k + 1];
				array[k + 1] = tmp;
			}
			k++;
		}
		j++;
	}
}

int	*sort_array(t_list *head)
{
	int	*array;
	int	size;
	int	i;

	i = 0;
	size = list_size(head);
	array = malloc(size * sizeof(int));
	while (i < size)
	{
		array[i++] = head->nbr;
		head = head->next;
	}
	array_swap(array, size);
	return (array);
}

void	give_index(t_list *head, int *array)
{
	int	i;
	int	size;

	size = list_size(head);
	while (head)
	{
		i = 0;
		while (i < size)
		{
			if (head->nbr == array[i])
				head->index = i;
			i++;
		}
		head = head->next;
	}
}

void	free_list(t_list **head)
{
	t_list	*node;

	node = NULL;
	if (head)
		node = *head;
	while (node)
	{
		node = (*head)->next;
		free((*head));
		*head = node;
	}
	head = NULL;
}

void	error(t_list **stack_a, t_list **stack_b, char **str, char *a)
{
	if (a || str)
	{
		free(a);
		free(str);
	}
	write(2, "Error\n", 6);
	free_list(stack_a);
	free_list(stack_b);
	exit(1);
}
