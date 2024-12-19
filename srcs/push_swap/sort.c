/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:47:42 by yfradj            #+#    #+#             */
/*   Updated: 2024/12/17 11:31:44 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sqrt(int nb)
{
	int	i;

	if (nb < 4)
		return (1);
	i = 2;
	while (i * i < nb)
		i++;
	if (i * i > nb)
	{
		if ((i * i - nb) < ((i - 1) * (i - 1) + (-nb)))
			return (i);
	}
	return (i - 1);
}

int	count_rotation(t_list *lb, int index)
{
	int	count;

	count = 0;
	while (lb && lb->s_index != index)
	{
		lb = lb->next;
		count++;
	}
	return (count);
}

void	chunk_sort1(t_list **la, t_list **lb, int size_a)
{
	int	size_b;
	int	range_chunk;

	size_b = 0;
	range_chunk = ft_sqrt(size_a) * 1.35;
	while (*la)
	{
		if ((*la)->s_index <= size_b)
		{
			pb(la, lb);
			rb(lb);
			size_b++;
		}
		else if ((*la)->s_index <= size_b + range_chunk)
		{
			pb(la, lb);
			size_b++;
		}
		else
			ra(la);
	}
}

void	chunk_sort2(t_list **la, t_list **lb, int size_b)
{
	int	rb_count;
	int	rrb_count;

	while (size_b - 1 >= 0)
	{
		rb_count = count_rotation(*lb, size_b - 1);
		rrb_count = (size_b + 1) - rb_count;
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
