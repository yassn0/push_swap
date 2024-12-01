/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:31:44 by yfradj            #+#    #+#             */
/*   Updated: 2024/11/29 16:16:29 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(s_list **begin_la)
{
	int		tmp;
	s_list	*lst;

	lst = *begin_la;
	if (!lst || !(lst->next))
		return ;
	tmp = lst->nb;
	lst->nb = lst->next->nb;
	lst->next->nb = tmp;
	// ft_printf("sa\n");
}

void	sb(s_list **begin_lb)
{
	int		tmp;
	s_list	*lst;

	lst = *begin_lb;
	if (!lst || !(lst->next))
		return ;
	tmp = lst->nb;
	lst->nb = lst->next->nb;
	lst->next->nb = tmp;
	// ft_printf("sb\n");
}

void	pa(s_list **begin_la, s_list **begin_lb)
{
	s_list	*la;
	s_list	*lb;

	la = *begin_la;
	lb = *begin_lb;
	if (!lb || !la)
		return ;
	ft_lstadd_front(begin_la, lb);
	// ft_printf("pb\n");
}

void	pb(s_list **begin_la, s_list **begin_lb)
{
	s_list	*la;
	s_list	*lb;

	la = *begin_la;
	lb = *begin_lb;
	if (!lb || !la)
		return ;
	ft_lstadd_front(begin_lb, la);
	// ft_printf("pb\n");
}
