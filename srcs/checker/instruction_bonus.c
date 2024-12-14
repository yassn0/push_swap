/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:31:44 by yfradj            #+#    #+#             */
/*   Updated: 2024/12/14 15:34:49 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	sa(t_list **begin_la)
{
	int		tmp;
	t_list	*lst;

	lst = *begin_la;
	if (!lst || !(lst->next))
		return ;
	tmp = lst->nb;
	lst->nb = lst->next->nb;
	lst->next->nb = tmp;
	ft_printf("sa\n");
}

void	sb(t_list **begin_lb)
{
	int		tmp;
	t_list	*lst;

	lst = *begin_lb;
	if (!lst || !(lst->next))
		return ;
	tmp = lst->nb;
	lst->nb = lst->next->nb;
	lst->next->nb = tmp;
	ft_printf("sb\n");
}

void	pa(t_list **la, t_list **lb)
{
	t_list	*temp;

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
	ft_printf("pa\n");
}

void	pb(t_list **la, t_list **lb)
{
	t_list	*temp;

	if (*la == NULL)
		return ;
	temp = *la;
	*la = (*la)->next;
	temp->next = *lb;
	*lb = temp;
	ft_printf("pb\n");
}

void	rr(t_list **la, t_list **lb)
{
	ra_no_comment(la);
	rb_no_comment(lb);
	ft_printf("rr\n");
}
