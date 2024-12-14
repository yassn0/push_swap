/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:30:28 by yfradj            #+#    #+#             */
/*   Updated: 2024/12/14 13:09:49 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **begin_la)
{
	t_list	*tmp;
	t_list	*end;

	if (!begin_la || !(*begin_la) || !((*begin_la)->next))
		return ;
	tmp = (*begin_la)->next;
	end = ft_lstlast(*begin_la);
	end->next = *begin_la;
	(*begin_la)->next = NULL;
	*begin_la = tmp;
	ft_printf("ra\n");
}

void	rb(t_list **begin_lb)
{
	t_list	*first;
	t_list	*last;

	if (!(*begin_lb) || !(*begin_lb)->next)
		return ;
	first = *begin_lb;
	last = *begin_lb;
	while (last->next)
		last = last->next;
	*begin_lb = first->next;
	first->next = NULL;
	last->next = first;
	ft_printf("rb\n");
}

void	rra(t_list **begin_la)
{
	t_list	*lst;
	t_list	*end;

	if (!begin_la || !(*begin_la) || !((*begin_la)->next))
		return ;
	lst = *begin_la;
	end = ft_lstlast(*begin_la);
	while (lst->next->next)
		lst = lst->next;
	lst->next = NULL;
	end->next = *begin_la;
	*begin_la = end;
	ft_printf("rra\n");
}

void	rrb(t_list **begin_lb)
{
	t_list	*prev;
	t_list	*current;

	prev = NULL;
	current = *begin_lb;
	if (!(*begin_lb) || !(*begin_lb)->next)
		return ;
	while (current->next)
	{
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	current->next = *begin_lb;
	*begin_lb = current;
	ft_printf("rrb\n");
}

void	rrr(t_list **la, t_list **lb)
{
	rra_no_comment(la);
	rrb_no_comment(lb);
	ft_printf("rrr\n");
}
