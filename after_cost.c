/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   after_cost.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:56:08 by yfradj            #+#    #+#             */
/*   Updated: 2024/12/09 17:55:12 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_top_a(s_list **begin_la, int nb_min_cost)
{
	int		position;
	s_list	*current;

	position = 0;
	current = *begin_la;
	while (current && current->nb != nb_min_cost)
	{
		position++;
		current = current->next;
	}
	if (!current)
		return ;
	if (position <= lst_size(begin_la) / 2)
	{
		while ((*begin_la)->nb != nb_min_cost)
			ra(begin_la);
	}
	else
	{
		while ((*begin_la)->nb != nb_min_cost)
			rra(begin_la);
	}
}

int	prepare_lb(s_list **lb, int n)
{
	s_list	*current;
	int		index;
	int		size;
	int		back;

	if (!(*lb) || !(*lb)->next)
		return (-1);
	current = *lb;
	index = 0;
	size = lst_size(lb);
	back = 0;
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
	// ft_printf("%d\n", index);
	
	if (index <= size / 2)
		while (index-- > 0)
			rb(lb);
	else
	{
		back += 1;
		index = size - index;
		while (index-- > 0)
			rrb(lb);
	}
	return (back);
}

void	go_back(s_list **lb, int back)
{
	// int	rrb_or_rb;
	
	// if (back > 100000)
	// {
	// 	rrb_or_rb = 1;
	// 	back -= 100000;
	// }
	// else
	// 	rrb_or_rb = 0;
	// back += 1;
	if (back == 1)
	{
		while (!is_sorted_dec(lb))
			rb(lb);
	}
	else
	{
		while (!is_sorted_dec(lb))
			rrb(lb);
	}
}
void	sort_three(s_list **begin_list)
{
	int	a;
	int	b;
	int	c;

	a = (*begin_list)->nb;
	b = (*begin_list)->next->nb;
	c = (*begin_list)->next->next->nb;
	if (a > b && b < c && a < c)
		sa(begin_list);
	else if (a > b && b > c)
	{
		sa(begin_list);
		rra(begin_list);
	}
	else if (a > b && b < c && a > c)
		ra(begin_list);
	else if (a < b && b > c && a < c)
	{
		sa(begin_list);
		ra(begin_list);
	}
	else if (a < b && b > c && a > c)
		rra(begin_list);
}

void	sort_three_dec(s_list **begin_list)
{
	int	a;
	int	b;
	int	c;

	a = (*begin_list)->nb;
	b = (*begin_list)->next->nb;
	c = (*begin_list)->next->next->nb;
	if (a < b && b > c && a > c)
		sa(begin_list);
	else if (a < b && b < c)
	{
		sa(begin_list);
		rra(begin_list);
	}
	else if (a < b && b > c && a < c)
		ra(begin_list);
	else if (a > b && b < c && a > c)
	{
		sa(begin_list);
		ra(begin_list);
	}
	else if (a > b && b < c && a < c)
		rra(begin_list);
}

void	move_to_position_a(s_list **begin_la, int n)
{
	s_list	*temp;
	int		position;
	int		size;

	temp = *begin_la;
	position = 0;
	size = lst_size(begin_la);
	while (temp && temp->nb < n)
	{
		position++;
		temp = temp->next;
	}
	if (position <= size / 2)
	{
		while (position > 0)
		{
			ra(begin_la);
			position--;
		}
	}
	else
	{
		while (position < size)
		{
			rra(begin_la);
			position++;
		}
	}
}

int	find_min(s_list **begin_list)
{
	s_list	*temp;
	int		min;

	temp = *begin_list;
	min = temp->nb;
	while (temp)
	{
		if (temp->nb < min)
			min = temp->nb;
		temp = temp->next;
	}
	return (min);
}
