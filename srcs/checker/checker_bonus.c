/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:34:47 by yfradj            #+#    #+#             */
/*   Updated: 2024/12/16 12:53:04 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
	char	*instruction;

	if (ac == 1)
		exit(0);
	split = get_split(ac, av);
	if (!split || !split[0])
		exit(1);
	if (check_error2(split) == 1 || check_error1(split) == 1
		|| double_number(split) == 1)
		return (error(split));
	la = create_list(split);
	lb = NULL;
	read_and_execute(&la, &lb);
	if (is_sorted(&la) && lst_size(&la) >= 2)
		ft_printf("OK");
	else
		ft_printf("KO");
	free_all(split, &la);
}
