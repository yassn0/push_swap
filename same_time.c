/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   same_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:05:46 by yfradj            #+#    #+#             */
/*   Updated: 2024/12/11 16:49:26 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_to_top_a(s_list **begin_la, int nb_min_cost)
{
	int		position;
	s_list	*current;
	int		count;
	int		size;

	position = 0;
	current = *begin_la;
	count = 0;
	size = lst_size(begin_la);
	while (current && current->nb != nb_min_cost)
	{
		position++;
		current = current->next;
	}
	if (!current)
		return (-1);
	current = *begin_la;
	if (position <= lst_size(begin_la) / 2)
	{
		while (current->nb != nb_min_cost)
		{
			current = current->next;
			count++; // ra
		}
	}
	else
	{
		while (current->nb != nb_min_cost)
		{
			current = current->next;
			count++; // ra
		}
		count = size - count;
		count += 100000;
	}
	return (count);
}

int	count_prepare_lb(s_list **lb, int n)
{
	int	index;
	int	size;
	int	count;

	count = 0;
	if (!(*lb) || !(*lb)->next)
		return (-1);
	index = calcul_index(lb, n);
	size = lst_size(lb);
	if (index <= size / 2)
		while (index-- > 0)
			count++; // rb
	else
	{
		index = size - index;
		count += 100000;
		while (index > 0)
		{
			count++; // rrb
			index--;
		}
	}
	return (count);
}

int	rrr_rr_possible(s_list **la, s_list **lb, int nb_min_cost)
{
	int	count_a;
	int	count_b;
	int	count;

	count_a = count_to_top_a(la, nb_min_cost);
	count_b = count_prepare_lb(lb, nb_min_cost);
	// ft_printf("\n%d\n", count_a);
	// ft_printf("%d\n\n", count_b);
	count = 0;
	if (count_a > 100000 && count_b > 100000) ///rrb rra
	{
		count_a -= 100000;
		count_b -= 100000;
		if (count_a > count_b)
			count = count_b;
		else
			count = count_a;
		// ft_printf("COUNT : %d\n", count);
		while (count > 0)
		{
			rrr(la, lb);
			count--;
		}
	}
	else if ((count_a < 100000 && count_b < 100000) && (count_a != 0 && count_b != 0)) //ra rb
	{
		if (count_a > count_b)
			count = count_b;
		else
			count = count_a;
		// ft_printf("COUNT : %d\n", count);
		while (count > 0)
		{
			rr(la, lb);
			count--;
		}
	
	}
	return (count_a - count_b);
}
