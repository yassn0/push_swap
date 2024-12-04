/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:24:49 by yfradj            #+#    #+#             */
/*   Updated: 2024/11/29 11:55:11 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	len_av(int ac, char **av)
{
	int	i;
	int	j;
	int	compt_char;

	i = 1;
	j = 0;
	compt_char = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			j++;
			compt_char++;
		}
		i++;
	}
	return (compt_char + (i - 1));
}

char	*create_str_for_split(int ac, char **av)
{
	int		i;
	char	*str;

	i = 1;
	str = "";
	ft_printf("%s", str);
	while (i < ac)
	{
		str = ft_strjoin(str, av[i]);
		if (!str)
			return (NULL);
		str = ft_strjoin(str, " ");
		if (!str)
			return(NULL);
		i++;
	}
	return (str);
}

char	**get_split(int ac, char **av)
{
	char **split;
	char *str;

	if (ac == 2)
		split = ft_split(av[1], ' '); // free after + securite
	else
	{
		str = create_str_for_split(ac, av);
		split = ft_split(str, ' ');
	}
	return (split);
}