/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:47:42 by yfradj            #+#    #+#             */
/*   Updated: 2024/12/14 14:48:37 by yfradj           ###   ########.fr       */
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

int	ft_sqrt(int number)
{
	int	i;

	if (number < 4)
		return (1);
	i = 2;
	while (i * i < number)
		i++;
	if (i * i > number)
	{
		if ((i * i - number) < ((i - 1) * (i - 1) + (-number)))
			return (i);
	}
	return (i - 1);
}

int	count_rotation(t_list *stack, int index)
{
	int	counter;

	counter = 0;
	while (stack && stack->s_index != index)
	{
		stack = stack->next;
		counter++;
	}
	return (counter);
}

void	k_sort1(t_list **la, t_list **lb, int size_a)
{
	int	size_b;
	int	range;

	size_b = 0;
	range = ft_sqrt(size_a) * 1.35;
	while (*la)
	{
		if ((*la)->s_index <= size_b)
		{
			pb(la, lb);
			rb(lb);
			size_b++;
		}
		else if ((*la)->s_index <= size_b + range)
		{
			pb(la, lb);
			size_b++;
		}
		else
			ra(la);
	}
}

void	k_sort2(t_list **la, t_list **lb, int size_b)
{
	int	rb_count;
	int	rrb_count;

	while (size_b - 1 >= 0)
	{
		rb_count = count_rotation(*lb, size_b - 1);
		rrb_count = (size_b + 3) - rb_count;
		if (rb_count <= rrb_count)
		{
			while ((*lb)->s_index != size_b - 1)
				rb(lb);
		}
		else
		{
			while ((*lb)->s_index != size_b - 1)
				rrb(lb);
		}
		pa(la, lb);
		size_b--;
	}
}
