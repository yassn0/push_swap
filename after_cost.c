/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   after_cost.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yassinfradj28@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:56:08 by yfradj            #+#    #+#             */
/*   Updated: 2024/12/04 17:58:32 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	move_to_top_a(s_list **begin_la, int nb_min_cost)
{
	int	cost_a;

	cost_a = closer_to_the_beginning_or_the_end(begin_la, nb_min_cost);
	if (cost_a <= 0)
		return (0);
	else if (cost_a <= lst_size(begin_la) / 2)
	{
		while ((*begin_la)->nb != nb_min_cost)
			ra(begin_la);
	}
	else
	{
		while ((*begin_la)->nb != nb_min_cost)
			rra(begin_la);
	}
	return (1);
}

int	move_to_position_b(s_list **begin_lb, int n)
{
	int cost_b = cost_sort_lb_for_pb(begin_lb, n);

	if (cost_b == 0)
		return (0);
	else if (cost_b <= lst_size(begin_lb) / 2)
	{
		while (cost_b-- > 0)
			rb(begin_lb);
	}
	else
	{
		while (cost_b-- > 0)
			rrb(begin_lb);
	}
	return (1);
}