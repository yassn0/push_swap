/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:19:58 by yfradj            #+#    #+#             */
/*   Updated: 2024/12/09 18:13:26 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

s_list	*ft_lstlast(s_list *lst)
{
	if (!(lst))
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int lst_size(s_list **begin_list)
{
    int     size;
    s_list  *current;

    size = 0;
    current = *begin_list;
    while (current)
    {
        size++;
        current = current->next;
    }
    return (size);
}

void	print_list(s_list **lst)
{
	s_list	*tmp;

	tmp = *lst;
	while (tmp)
	{
		ft_printf("%d\t", tmp->nb);
		tmp = tmp->next;
	}
}
