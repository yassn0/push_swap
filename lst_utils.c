/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:14:34 by yfradj            #+#    #+#             */
/*   Updated: 2024/11/29 14:48:11 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

s_list	*ft_lstnew(int n)
{
	s_list	*new;

	new = malloc(1 * sizeof(s_list));
	if (!new)
		return (NULL);
	new->nb = n;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(s_list **lst, int n)
{
	s_list	*tmp;
	s_list	*new;

	new = ft_lstnew(n);
	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = ft_lstlast(*lst);
	tmp->next = new;
}

void	ft_lstadd_front(s_list **lst, s_list *new)
{
	if (!new)
		return ;
	new->next = *lst;
	*lst = new;
}

void	ft_lstclear(s_list **lst)
{
	s_list	*tmp;

	tmp = NULL;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}
