/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yassinfradj28@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:31:44 by yfradj            #+#    #+#             */
/*   Updated: 2024/12/04 18:00:52 by yfradj           ###   ########.fr       */
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
    s_list *temp;

    if (*la == NULL)
        return;
    temp = *lb;
    *lb = (*lb)->next;
    temp->next = *la;
    *la = temp;
    ft_printf("pa\n");
}

void pb(s_list **la, s_list **lb)
{
    s_list *temp;

    if (*la == NULL)
        return;
    temp = *la;
    *la = (*la)->next;
    temp->next = *lb;
    *lb = temp;
    ft_printf("pb\n");
}
