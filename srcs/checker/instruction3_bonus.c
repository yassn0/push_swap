/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction3_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:55:07 by yfradj            #+#    #+#             */
/*   Updated: 2024/12/14 15:34:54 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ra_no_comment(t_list **begin_la)
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
}

void	rb_no_comment(t_list **begin_lb)
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
}

void	rra_no_comment(t_list **begin_la)
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
}

void	rrb_no_comment(t_list **begin_lb)
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
}
