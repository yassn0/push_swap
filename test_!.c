// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   test_!.c                                           :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/12/11 15:25:32 by yfradj            #+#    #+#             */
// /*   Updated: 2024/12/11 16:15:11 by yfradj           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "push_swap.h"

// int	ft_find_place_b(s_list *lb, int nb_min_cost)
// {
// 	int		i;
// 	s_list	*current;

// 	i = 1;
// 	if (nb_min_cost > lb->nb && nb_min_cost < ft_lstlast(lb)->nb)
// 		i = 0;
// 	else if (nb_min_cost > ft_max(lb) || nb_min_cost < ft_min(lb))
// 		i = calcul_index(lb, ft_max(lb));
// 	else
// 	{
// 		current = lb->next;
// 		while (lb->nb < nb_min_cost || current->nb > nb_min_cost)
// 		{
// 			lb = lb->next;
// 			current = lb->next;
// 			i++;
// 		}
// 	}
// 	return (i);
// }

// int	ft_max(s_list *la)
// {
// 	int		i;

// 	i = la->nb;
// 	while (la)
// 	{
// 		if (la->nb > i)
// 			i = la->nb;
// 		la = la->next;
// 	}
// 	return (i);
// }

// int	ft_min(s_list *la)
// {
// 	int		i;

// 	i = la->nb;
// 	while (la)
// 	{
// 		if (la->nb < i)
// 			i = la->nb;
// 		la = la->next;
// 	}
// 	return (i);
// }

// int	ft_case_rarb(s_list *a, s_list *b, int c)
// {
// 	int	i;

// 	i = ft_find_place_b(b, c);
// 	if (i < ft_find_index(a, c))
// 		i = ft_find_index(a, c);
// 	return (i);
// }

// int	ft_case_rrarrb(s_list *a, s_list *b, int c)
// {
// 	int	i;

// 	i = 0;
// 	if (ft_find_place_b(b, c))
// 		i = ft_lstsize(b) - ft_find_place_b(b, c);
// 	if ((i < (ft_lstsize(a) - calcul_index(a, c))) && calcul_index(a, c))
// 		i = ft_lstsize(a) - calcul_index(a, c);
// 	return (i);
// }

// int	ft_rotate_type_ab(s_list *a, s_list *b)
// {
// 	int		i;
// 	s_list	*tmp;

// 	tmp = a;
// 	i = ft_case_rrarrb(a, b, a->nb);
// 	while (tmp)
// 	{
// 		if (i > ft_case_rarb(a, b, tmp->nb))
// 			i = ft_case_rarb(a, b, tmp->nb);
// 		if (i > ft_case_rrarrb(a, b, tmp->nb))
// 			i = ft_case_rrarrb(a, b, tmp->nb);
// 		tmp = tmp->next;
// 	}
// 	return (i);
// }

// s_list	**ft_sort_a(s_list **stack_a, s_list **stack_b)
// {
// 	int		i;
// 	s_list	*tmp;

// 	while (*stack_b)
// 	{
// 		tmp = *stack_b;
// 		i = ft_rotate_type_ba(*stack_a, *stack_b);
// 		while (i >= 0)
// 		{
// 			if (i == ft_case_rarb_a(*stack_a, *stack_b, tmp->nb))
// 				i = ft_apply_rarb(stack_a, stack_b, tmp->nb, 'b');
// 			else if (i == ft_case_rrarrb_a(*stack_a, *stack_b, tmp->nb))
// 				i = ft_apply_rrarrb(stack_a, stack_b, tmp->nb, 'b');
// 			else
// 				tmp = tmp->next;
// 		}
// 	}
// 	return (stack_a);
// }