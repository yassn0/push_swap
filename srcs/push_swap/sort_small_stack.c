/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:05:51 by yfradj            #+#    #+#             */
/*   Updated: 2024/12/16 14:05:52 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **begin_list)
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

void	small_sort_1(t_list **la, t_list **lb)
{
	if ((*lb)->nb < (*la)->nb)
		pa(la, lb);
	else if ((*lb)->nb > (*la)->nb && (*lb)->nb < (*la)->next->nb)
	{
		ra(la);
		pa(la, lb);
		rra(la);
	}
	else if ((*lb)->nb > (*la)->next->nb && (*lb)->nb < (*la)->next->next->nb)
	{
		rra(la);
		pa(la, lb);
		rra(la);
		rra(la);
	}
	else if ((*lb)->nb > (*la)->next->next->nb)
	{
		pa(la, lb);
		ra(la);
	}
}

void	help_line(t_list **la, t_list **lb)
{
	rra(la);
	pa(la, lb);
	ra(la);
	ra(la);
}

void	small_sort2(t_list **la, t_list **lb)
{
	if ((*lb)->nb < (*la)->nb)
		pa(la, lb);
	else if ((*lb)->nb > (*la)->next->nb && (*lb)->nb < (*la)->next->next->nb)
	{
		ra(la);
		pa(la, lb);
		sa(la);
		rra(la);
	}
	else if ((*lb)->nb > (*la)->nb && (*lb)->nb < (*la)->next->nb)
	{
		ra(la);
		pa(la, lb);
		rra(la);
	}
	else if ((*lb)->nb > (*la)->next->next->next->nb)
	{
		pa(la, lb);
		ra(la);
	}
	else if ((*lb)->nb > (*la)->next->next->nb
		&& (*lb)->nb < (*la)->next->next->next->nb)
	{
		help_line(la, lb);
	}
}

void	small_sort(t_list **la, t_list **lb)
{
	pb(la, lb);
	pb(la, lb);
	sort_three(la);
	while (*lb)
	{
		if (lst_size(la) == 3)
			small_sort_1(la, lb);
		else if (lst_size(la) == 4)
			small_sort2(la, lb);
	}
}
