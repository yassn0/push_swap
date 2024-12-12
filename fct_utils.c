/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:10:39 by yfradj            #+#    #+#             */
/*   Updated: 2024/12/12 16:49:15 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi_max(const char *str)
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
		return (0);
	if ((sign) == -1)
		return (-somme);
	return ((int)somme);
}

void	sort_two_or_one(s_list **la)
{
	if (is_sorted(la))
		return ;
	if (lst_size(la) == 2)
		sa(la);
}

void	free_all(char **split, s_list **la)
{
	if (la)
	{
		ft_lstclear(la);
		free_tab(split);
	}
}

int	special_case(s_list **la, char **split)
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
	return (1);
}