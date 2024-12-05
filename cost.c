/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 17:44:35 by yfradj            #+#    #+#             */
/*   Updated: 2024/12/05 16:03:19 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted_dec(s_list **begin_list)
{
	s_list	*lst;

	lst = *begin_list;
	while (lst && lst->next)
	{
		if (lst->nb < lst->next->nb)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	is_sorted(s_list **begin_list)
{
	s_list	*lst;

	lst = *begin_list;
	while (lst && lst->next)
	{
		if (lst->nb > lst->next->nb)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int calcul_index(s_list **begin_list, int n)
{
    int     i;
    s_list  *lst;

    i = 0;
    lst = *begin_list;
    while (lst)
    {
        if (lst->nb == n)
            return (i);
        lst = lst->next;
        i++;
    }
    return (-1);
}

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
	if (!lst)
		return (-1);
	end = lst_size(begin_list) - deb;
	if (deb == 0)
		return (0);
	if (deb > end)
		return (end); // closest to end, so use rra after
	else
		return (deb); // use ra after
}

int cost_sort_lb_for_pb(s_list **lb, int n)
{
    int     index;
    int     size_l;

    index = calcul_index(lb, n);
    size_l = lst_size(lb);
    if (index == -1)
        return INT_MAX;
    if (index <= size_l / 2)
        return index; // rb
    else
        return size_l - index; // rrb
}

int	calcul_cost(s_list **begin_la, s_list **begin_lb, int n)
{
	int	cost;

	cost = 0;
	cost = closer_to_the_beginning_or_the_end(begin_la, n);
	if (cost == -1)
		return (INT_MAX);
	cost += cost_sort_lb_for_pb(begin_lb, n);
	return (cost);
}

int n_min_cost(s_list **begin_la, s_list **begin_lb)
{
    int     min_cost;
    int     current_cost;
    int     min_value;
    s_list  *temp_la;

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

