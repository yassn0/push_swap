/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:34:47 by yfradj            #+#    #+#             */
/*   Updated: 2024/12/09 19:22:56 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted_dec(s_list **begin_list)
{
	s_list	*lst;

	lst = *begin_list;
	while (lst && lst->next)
	{
		if (lst->nb < lst->next->nb)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	is_sorted(s_list **begin_list)
{
	s_list	*lst;

	lst = *begin_list;
	while (lst && lst->next)
	{
		if (lst->nb > lst->next->nb)
			return (0);
		lst = lst->next;
	}
	return (1);
}

s_list	*create_list(char **tab)
{
	s_list	*lst;
	int		i;

	i = 0;
	lst = NULL;
	while (tab[i])
	{
		ft_lstadd_back(&lst, ft_atoi(tab[i]));
		i++;
	}
	return (lst);
}

void	ft_algo(s_list **la, s_list **lb)
{
	int	nb_min_cost;
	int	back;
	int	size;

	nb_min_cost = 0;
	back = 0;
	while (lst_size(la) > 0)
	{
		nb_min_cost = n_min_cost(la, lb);
		move_to_top_a(la, nb_min_cost);
		back = prepare_lb(lb, nb_min_cost);
		pb(la, lb);
		if (!is_sorted(lb))
			go_back(lb, back);
	}
}

void	ft_algo2(s_list **la, s_list **lb, int size)
{
	while (size > 0)
	{
		if (lst_size(lb) == 0)
			break ;
		pa(la, lb);
		size--;
	}
}

int	main(int ac, char **av)
{
	s_list	*la;
	s_list	*lb;
	char	**split;
	int		size;
	int		nb_min_cost;
	int		back;

	if (ac == 1)
		exit(0);
	split = get_split(ac, av); // securite
	if (check_error2(split) == 1 || check_error1(split) == 1)
		return (error());
	else if (double_number(split) == 1)
		return (error());
		
	la = create_list(split);
	size = lst_size(&la);
	lb = NULL;
	back = 0;
	pb(&la, &lb);
	pb(&la, &lb);
	pb(&la, &lb);
	sort_three_dec(&lb); // or less
	ft_algo(&la, &lb);
	ft_algo2(&la, &lb, size);
	print_list(&la);
	// free tout
}

// int main(int ac, char **av)
// {
// 	s_list	*lb;
// 	char	**split;
// 	s_list	*tmp;

// 	if (ac == 1)
// 		exit(0);
// 	split = get_split(ac, av); // securite
// 	if (check_error2(split) == 1 || check_error1(split) == 1)
// 		return (error());
// 	else if (double_number(split) == 1)
// 		return (error());

// 	lb = create_list(split);
// 	int back = prepare_lb(&lb, 3);
// 	s_list *la = ft_lstnew(3);
// 	pb(&la, &lb);
// 	go_back(&lb, back);
// 	print_list(&lb);
// }