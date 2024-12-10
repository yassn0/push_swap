/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 17:44:35 by yfradj            #+#    #+#             */
/*   Updated: 2024/12/10 10:27:55 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	closer_to_the_beginning_or_the_end(s_list **begin_list, int n)
{
	s_list	*lst;
	int		deb;
	int		end;

	lst = *begin_list;
	deb = 0;
	while (lst && lst->nb != n)
	{
		lst = lst->next;
		deb++;
	}
	end = lst_size(begin_list) - deb;
	if (deb == 0)
		return (0);
	if (deb > end)
		return (end);
	else
		return (deb);
}

int	cost_sort_lb_for_pb(s_list **lb, int n)
{
	s_list	*lst;
	int		index;
	int		size_l;

	lst = *lb;
	index = 0;
	size_l = lst_size(lb);
	while (lst)
	{
		if ((lst->nb > n && (!lst->next || lst->next->nb < n))
			|| (lst->next == NULL && lst->nb < n && (*lb)->nb > n))
			break ;
		lst = lst->next;
		index++;
	}
	if (index <= size_l / 2)
		return (index);
	else
		return (size_l - index);
}

int	calcul_cost(s_list **begin_la, s_list **begin_lb, int n)
{
	int	cost;

	cost = 0;
	cost = closer_to_the_beginning_or_the_end(begin_la, n);
	cost += cost_sort_lb_for_pb(begin_lb, n);
	return (cost);
}

int	n_min_cost(s_list **begin_la, s_list **begin_lb)
{
	int		min_cost;
	int		current_cost;
	int		min_value;
	s_list	*temp_la;

	temp_la = *begin_la;
	min_cost = INT_MAX;
	min_value = temp_la->nb;
	while (temp_la)
	{
		current_cost = calcul_cost(begin_la, begin_lb, temp_la->nb);
		if (current_cost < min_cost)
		{
			min_cost = current_cost;
			min_value = temp_la->nb;
		}
		temp_la = temp_la->next;
	}
	return (min_value);
}
