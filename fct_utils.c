/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:10:39 by yfradj            #+#    #+#             */
/*   Updated: 2024/12/09 19:08:50 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi_max(const char *str)
{
	int		i;
	int		sign;
	long	somme;

	i = 0;
	somme = 0;
	sign = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if ((str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9'))
	{
		somme = (somme * 10) + (str[i] - 48);
		i++;
	}
	if (somme > INT_MAX || somme < INT_MIN)
		return (0);
	if ((sign) == -1)
		return (-somme);
	return ((int)somme);
}
int	calcul_index(s_list **lb, int n)
{
	s_list *current;
	int index;

	index = 0;
	current = *lb;
	while (current)
	{
		if (current->nb > n && (!current->next || current->next->nb < n))
		{
			index++;
			break ;
		}
		current = current->next;
		index++;
	}
	return (index);
}