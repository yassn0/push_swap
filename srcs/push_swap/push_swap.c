/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:34:47 by yfradj            #+#    #+#             */
/*   Updated: 2024/12/14 14:49:20 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp)
	{
		ft_printf("%d\t", tmp->nb);
		tmp = tmp->next;
	}
}

int	is_sorted(t_list **begin_list)
{
	t_list	*lst;

	lst = *begin_list;
	while (lst && lst->next)
	{
		if (lst->nb > lst->next->nb)
			return (0);
		lst = lst->next;
	}
	return (1);
}

t_list	*create_list(char **tab)
{
	t_list	*lst;
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
	t_list	*la;
	t_list	*lb;
	char	**split;
	int		size_a;

	if (ac == 1)
		exit(0);
	split = get_split(ac, av);
	if (!split)
		exit(1);
	if (check_error2(split) == 1 || check_error1(split) == 1
		|| double_number(split) == 1)
		return (error(split));
	la = create_list(split);
	if (special_case(&la, split) == 0)
		return (0);
	lb = NULL;
	size_a = lst_size(&la);
	put_index(&la);
	k_sort1(&la, &lb, size_a);
	k_sort2(&la, &lb, size_a);
	print_list(&la);
	free_all(split, &la);
}
