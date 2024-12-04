/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yassinfradj28@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:56:08 by yfradj            #+#    #+#             */
/*   Updated: 2024/12/04 16:43:33 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(s_list **begin_lst)
{
	int		max;
	s_list	*lst;

	lst = *begin_lst;
	max = lst->nb;
	while (lst)
	{
		if (lst->nb > max)
			max = lst->nb;
		lst = lst->next;
	}
	return (max);
}

int	find_target_index(s_list **begin_lst, int target)
{
	int		index;
	s_list	*lst;

	lst = *begin_lst;
	index = 0;
	while (lst)
	{
		if (lst->nb == target)
			break ;
		index++;
		lst = lst->next;
	}
	return (index);
}

void	sort_stack_b(s_list **begin_lb)
{
	int	max;
	int	target_index;
	int	size;

	if (!(*begin_lb) || !(*begin_lb)->next)
		return ;
	while (!is_sorted_dec(begin_lb))
	{
		max = find_max(begin_lb);
		size = lst_size(begin_lb);
		target_index = find_target_index(begin_lb, max);
		if (target_index <= size / 2)
		{
			while ((*begin_lb)->nb != max)
				rb(begin_lb);
		}
		else
		{
			while ((*begin_lb)->nb != max)
				rrb(begin_lb);
		}
	}
}

