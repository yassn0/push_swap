/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:10:39 by yfradj            #+#    #+#             */
/*   Updated: 2024/12/16 12:46:59 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi_max(const char *str)
{
	int		i;
	int		sign;
	long	somme;

	i = 0;
	somme = 0;
	sign = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if ((str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9'))
	{
		somme = (somme * 10) + (str[i] - 48);
		i++;
	}
	if (somme > INT_MAX || somme < INT_MIN)
		return (LONG_MIN);
	if ((sign) == -1)
		return (-somme);
	return (somme);
}

void	sort_two_or_one(t_list **la)
{
	if (is_sorted(la))
		return ;
	if (lst_size(la) == 2)
		sa(la);
}

void	free_all(char **split, t_list **la)
{
	if (la)
	{
		ft_lstclear(la);
		free_tab(split);
	}
}

int	special_case(t_list **la, t_list **lb, char **split)
{
	if (is_sorted(la))
	{
		free_all(split, la);
		return (0);
	}
	if (lst_size(la) < 3)
	{
		sort_two_or_one(la);
		free_all(split, la);
		return (0);
	}
	if (lst_size(la) == 3)
	{
		sort_three(la);
		free_all(split, la);
		return (0);
	}
	if (lst_size(la) == 5)
	{
		small_sort(la, lb);
		free_all(split, la);
		return (0);
	}
	return (1);
}
