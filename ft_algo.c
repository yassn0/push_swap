/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:29:54 by yfradj            #+#    #+#             */
/*   Updated: 2024/12/12 16:51:54 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

// void	ft_algo1(s_list **la, s_list **lb)
// {
// 	int	nb_min_cost;
// 	int	back;
// 	int	size;
// 	int	i;
// 	int	rest;

// 	nb_min_cost = 0;
// 	back = 0;
// 	while (lst_size(la) > 3)
// 	{
// 		nb_min_cost = n_min_cost(la, lb);
// 		rest = rrr_rr_possible(la, lb, nb_min_cost); // a or b
		
		
// 		if (rest != 0)
// 		{
// 			move_to_top_a(la, nb_min_cost);
// 			back = prepare_lb(lb, nb_min_cost);
// 			pb(la, lb);
// 		}
// 		if (!is_sorted(lb))
// 			go_back(lb, back);
// 	}
// }

// void	ft_algo2(s_list **la, s_list **lb, int size)
// {
// 	while (size > 0)
// 	{
// 		if (lst_size(lb) == 0)
// 			break ;
// 		pa(la, lb);
// 		size--;
// 	}
// }

// void	ft_algo(s_list **la, s_list **lb, int size)
// {
// 	pb(la, lb);
// 	pb(la, lb);
// 	ft_algo1(la, lb);
// 	ft_algo2(la, lb, size);
// }
