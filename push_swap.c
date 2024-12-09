/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:34:47 by yfradj            #+#    #+#             */
/*   Updated: 2024/12/09 18:04:58 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	main(int ac, char **av)
{
	s_list	*la;
	s_list	*lb;
	char	**split;
	s_list	*tmp;
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
	
	while (lst_size(&la) > 0)
	{
		nb_min_cost = n_min_cost(&la, &lb);
		// ft_printf(" min_cost : %d\n", nb_min_cost);
		// print_list(&lb);
		move_to_top_a(&la, nb_min_cost);
		back = prepare_lb(&lb, nb_min_cost);
		// print_list(&lb);
		pb(&la, &lb);
		if (!is_sorted(&lb))
			go_back(&lb, back);
	}
	print_list(&lb);
	// print_list(&la);
	tmp = lb;
	while (lst_size(&tmp) > 0)
	{
		// ft_printf("size of lb = %d\n", lst_size(&lb));
		pa(&la, &tmp);
		
	}
	// print_list(&la);
	// print_list(&lb);
	// sort_three(&la);
	// while (lst_size(&tmp) > 0)
	// {
	// 	pa(&la, &tmp);
	// }
	// while (la->nb != find_min(&la))
	// 	ra(&la);
	// print_list(&la);
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