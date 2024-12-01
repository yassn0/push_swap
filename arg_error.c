/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:06:03 by yfradj            #+#    #+#             */
/*   Updated: 2024/11/28 16:57:10 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_error1(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i] != NULL)
	{
		j = 0;
		while (tab[i][j])
		{
			if (ft_isdigit(tab[i][j]) == 0 && tab[i][j] != ' ')
				if (tab[i][j] != '+' && tab[i][j] != '-')
					return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_error2(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i] != NULL)
	{
		j = ft_strlen(tab[i]);
		if (ft_atoi_max(tab[i]) == 0 && tab[i][j - 1] != '0')
			return (1);
		i++;
	}
	return (0);
}

int	double_number(char **tab)
{
	int	i;
	int	j;
	int	save;

	i = 0;
	while (tab[i] != NULL)
	{
		save = ft_atoi(tab[i]);
		j = i + 1;
		while (tab[j] != NULL)
		{
			if (save == ft_atoi(tab[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	error(void)
{
	ft_printf("Error\n");
	return (1);
}
