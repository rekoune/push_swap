/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arekoune <arekoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 01:34:38 by arekoune          #+#    #+#             */
/*   Updated: 2024/04/18 21:49:46 by arekoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				nbr;
	int				index;
	struct s_list	*next;
}					t_list;

// switch_to_integer.c
char				**ft_split(char *str, char c, t_list **head);
int					ft_atoi(char *str, t_list **head);
int					str_len(char *str, char c);
int					counte(char *str, char c);
char				*sub_str(char *str, int len);

// utils.c
t_list				*new_node(int nb);
void				add_front(t_list **head, t_list *new);
int					list_size(t_list *head);
void				add_back(t_list **head, t_list *new);
int					max_index(t_list *head);

// push_swap.c
t_list				*put_in_a(int ac, char **av);
void				put_in_b(t_list **stack_a, t_list **stack_b);
void				sorting_a(t_list **stack_a, t_list **stack_b);
void				ft_main(t_list **stack_a, t_list **stack_b);

// rules.c
void				swap(t_list **stack, char c, int a);
void				swap_a_b(t_list **stack_a, t_list **stack_b, int a);
void				push(t_list **stack_1, t_list **stack_2, char c, int a);
void				rotate(t_list **head, char c, int a);
void				rotate_a_b(t_list **stack_a, t_list **stack_b, int a);

// array.c
int					*sort_array(t_list *head);
void				give_index(t_list *head, int *array);
void				array_swap(int *array, int i);
void				free_list(t_list **head);
void				error(t_list **stack);

// sort_less.c
void				sort_5(t_list **stack_a, t_list **stack_b);
void				sort_3(t_list **head);
int					order_check(t_list *head);
int					repetation(t_list *head);
int					position(t_list *head, int max);

// utils2.c
void				reverse_rotate(t_list **head, char c, int a);
void				reverse_rotate_all(t_list **stack_a, t_list **stack_b,
						int a);
void				ft_write(char *str, char c);

#endif