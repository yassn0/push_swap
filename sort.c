/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:47:42 by yfradj            #+#    #+#             */
/*   Updated: 2024/12/12 16:45:15 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	count_rotation(s_list *stack, int index)
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

void	k_sort1(s_list **la, s_list **lb, int length)
{
	int	i;
	int	range;

	i = 0;
	range = ft_sqrt(length) * 14 / 10;
	while (*la)
	{
		if ((*la)->s_index <= i)
		{
			pb(la, lb);
			rb(lb);
			i++;
		}
		else if ((*la)->s_index <= i + range)
		{
			pb(la, lb);
			i++;
		}
		else
			ra(la);
	}
}

void	k_sort2(s_list **la, s_list **lb, int length)
{
	int	rb_count;
	int	rrb_count;

	while (length - 1 >= 0)
	{
		rb_count = count_rotation(*lb, length - 1);
		rrb_count = (length + 3) - rb_count;
		if (rb_count <= rrb_count)
		{
			while ((*lb)->s_index != length - 1)
				rb(lb);
		}
		else
		{
			while ((*lb)->s_index != length - 1)
				rrb(lb);
		}
		pa(la, lb);
		length--;
	}
}
