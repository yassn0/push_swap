/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:30:28 by yfradj            #+#    #+#             */
/*   Updated: 2024/11/29 17:15:22 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(s_list **begin_la)
{
	s_list	*tmp;
	s_list	*end;

	if (!begin_la || !(*begin_la) || !((*begin_la)->next))
		return ;
	tmp = (*begin_la)->next;
	end = ft_lstlast(*begin_la);
	end->next = *begin_la;
	(*begin_la)->next = NULL;
	*begin_la = tmp;
	// ft_printf("ra\n");
}

void	rb(s_list **begin_lb)
{
	s_list	*tmp;
	s_list	*end;

	if (!begin_lb || !(*begin_lb) || !((*begin_lb)->next))
		return ;
	tmp = (*begin_lb)->next;
	end = ft_lstlast(*begin_lb);
	end->next = *begin_lb;
	(*begin_lb)->next = NULL;
	*begin_lb = tmp;
	// ft_printf("rb\n");
}

void	rra(s_list **begin_la)
{
	s_list *lst;
	s_list *tmp2;
	s_list *end;

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

void	rra(s_list **begin_la)
{
	s_list *lst;
	s_list *tmp2;
	s_list *end;

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