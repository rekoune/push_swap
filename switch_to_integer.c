/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_to_integer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arekoune <arekoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 01:26:32 by arekoune          #+#    #+#             */
/*   Updated: 2024/04/20 10:30:51 by arekoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *str, t_list **head, char **a)
{
	long	nb;
	int		i;
	int		sign;

	i = 0;
	nb = 0;
	sign = 1;
	if ((str[i] == '-' || str[i] == '+') && str[i + 1] == '\0')
		error(head, a, str, 1);
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			error(head, a, str, 1);
		nb = nb * 10 + (str[i++] - 48);
	}
	if ((nb * sign > 2147483647) || (nb * sign < -2147483648))
		error(head, a, str, 1);
	return (nb * sign);
}

int	str_len(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

int	counte(char *str, char c)
{
	int	i;
	int	nf;
	int	counter;

	i = 0;
	nf = 1;
	counter = 0;
	while (str[i])
	{
		if (str[i] == c)
			nf = 1;
		else if (str[i] != c && nf == 1)
		{
			nf = 0;
			counter++;
		}
		i++;
	}
	return (counter);
}

char	*sub_str(char *str, int len)
{
	int		i;
	char	*s;

	i = 0;
	s = malloc((len + 1) * sizeof(char));
	while (i < len)
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	**ft_split(char *str, char c, t_list **head)
{
	int		n_word;
	char	**s;
	int		i;

	i = 0;
	n_word = counte(str, c);
	if (n_word == 0)
		error(head, NULL, NULL, 0);
	s = malloc((n_word + 1) * sizeof(char *));
	while (i < n_word)
	{
		while (*str == c)
			str++;
		if (*str)
			s[i++] = sub_str(str, str_len(str, c));
		str += str_len(str, c);
	}
	s[i] = NULL;
	return (s);
}
