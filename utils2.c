/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arekoune <arekoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:41:05 by arekoune          #+#    #+#             */
/*   Updated: 2024/04/18 21:47:32 by arekoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_list **head, char c, int a)
{
	t_list	*last_node;
	t_list	*befor_last_node;
	t_list	*first_node;
	int		size;
	int		i;

	i = 1;
	size = list_size(*head);
	if (size > 1)
	{
		last_node = *head;
		befor_last_node = *head;
		first_node = *head;
		while (last_node->next)
			last_node = last_node->next;
		while (i++ < (size - 1))
			befor_last_node = befor_last_node->next;
		*head = last_node;
		last_node->next = first_node;
		befor_last_node->next = NULL;
		if (a > 0)
			ft_write("rr", c);
	}
}

void	reverse_rotate_all(t_list **stack_a, t_list **stack_b, int a)
{
	reverse_rotate(stack_a, 'a', 0);
	reverse_rotate(stack_b, 'b', 0);
	if (a > 0)
		write(1, "rrr\n", 4);
}

void	ft_write(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}

t_list	*put_in_a_bonus(int ac, char **av)
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
			node = new_node(ft_atoi(str[j], &head));
			free(str[j]);
			add_back(&head, node);
			j++;
		}
		free(str);
		i++;
	}
	return (head);
}

int	compare(char *str, char *line)
{
	int	i;

	i = 0;
	while (str[i] && line[i])
	{
		if (str[i] != line[i])
			return (str[i] - line[i]);
		i++;
	}
	return (str[i] - line[i]);
}
