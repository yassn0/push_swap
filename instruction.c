/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:31:44 by yfradj            #+#    #+#             */
/*   Updated: 2024/12/09 19:00:44 by yfradj           ###   ########.fr       */
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
	ft_printf("sa\n");
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
	ft_printf("sb\n");
}

void	pa(s_list **la, s_list **lb)
{
	s_list	*temp;

	if (*lb == NULL)
		return ;
	temp = *lb;
	*lb = (*lb)->next;
	if (*la == NULL)
	{
		temp->next = NULL;
		*la = temp;
	}
	else
	{
		temp->next = *la;
		*la = temp;
	}
}

void	pb(s_list **la, s_list **lb)
{
	s_list	*temp;

	if (*la == NULL)
		return ;
	temp = *la;
	*la = (*la)->next;
	temp->next = *lb;
	*lb = temp;
	ft_printf("pb\n");
}
