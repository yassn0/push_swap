/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yassinfradj28@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:34:47 by yfradj            #+#    #+#             */
/*   Updated: 2024/12/04 18:20:45 by yfradj           ###   ########.fr       */
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
	int		size;
	int		nb_min_cost;

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
	// pb(&la, &lb);
	// pb(&la, &lb);
	// print_list(&la);
	// ft_printf("\n");
	// print_list(&lb);
	print_list(&la);
	ft_printf("\n");
	while (lst_size(&lb) != size)
	{
		ft_printf("\n");
		nb_min_cost = n_min_cost(&la, &lb);
		move_to_top_a(&la, nb_min_cost);
		move_to_position_b(&lb, nb_min_cost);
		pb(&la, &lb);
		print_list(&lb);
		
	}
	while (lst_size(&lb) > 0)
		pa(&lb, &la);

}
