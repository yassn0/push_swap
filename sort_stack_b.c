/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:56:08 by yfradj            #+#    #+#             */
/*   Updated: 2024/12/09 15:29:50 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(s_list **begin_lst)
{
	int		max;
	s_list	*lst;

	lst = *begin_lst;
	max = lst->nb;
	while (lst)
	{
		if (lst->nb > max)
			max = lst->nb;
		lst = lst->next;
	}
	return (max);
}

int	find_target_index(s_list **begin_lst, int target)
{
	int		index;
	s_list	*lst;

	lst = *begin_lst;
	index = 0;
	while (lst)
	{
		if (lst->nb == target)
			break ;
		index++;
		lst = lst->next;
	}
	return (index);
}

void	sort_stack_b(s_list **lb)
{
    s_list *current;
    s_list *max;
    int size;
    int index;
    int moves;

    if (!(*lb) || !(*lb)->next)
        return;

    // Trouver le plus grand élément dans `STACK_B`
    current = *lb;
    max = current;
    index = 0;
    size = 0;

    while (current)
    {
        if (current->nb > max->nb)
        {
            max = current;
            index = size;
        }
        current = current->next;
        size++;
    }

    // Calcule le coût pour aligner le maximum au sommet
    if (index <= size / 2)
    {
        // Effectuer des rotations RB pour aligner le maximum
        while (index-- > 0)
            rb(lb);
    }
    else
    {
        // Effectuer des rotations inversées RRB
        moves = size - index;
        while (moves-- > 0)
            rrb(lb);
    }
}

