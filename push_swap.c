/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:34:47 by yfradj            #+#    #+#             */
/*   Updated: 2024/12/10 11:47:05 by yfradj           ###   ########.fr       */
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

int	main(int ac, char **av)
{
	s_list	*la;
	s_list	*lb;
	char	**split;
	int		size;

	if (ac == 1)
		exit(0);
	split = get_split(ac, av);
	if (check_error2(split) == 1 || check_error1(split) == 1)
		return (error(split));
	else if (double_number(split) == 1)
		return (error(split));
	la = create_list(split);
	if (special_case(&la, split) == 0)
		return (0);
	size = lst_size(&la);
	lb = NULL;
	ft_algo(&la, &lb, size);
	free_all(split, &la);
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