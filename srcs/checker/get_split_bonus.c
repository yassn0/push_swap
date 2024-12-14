/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_split_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:24:49 by yfradj            #+#    #+#             */
/*   Updated: 2024/12/14 15:34:46 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
	char	*tmp;

	i = 1;
	str = "";
	while (i < ac)
	{
		tmp = str;
		str = ft_strjoin(tmp, av[i]);
		if (tmp && *tmp != '\0')
			free(tmp);
		if (!str)
			return (NULL);
		tmp = str;
		str = ft_strjoin(tmp, " ");
		if (tmp)
			free(tmp);
		if (!str)
			return (NULL);
		i++;
	}
	return (str);
}

char	**get_split(int ac, char **av)
{
	char	**split;
	char	*str;

	str = NULL;
	if (ac == 2)
	{
		split = ft_split(av[1], ' ');
		if (!split)
			return (NULL);
	}
	else
	{
		str = create_str_for_split(ac, av);
		split = ft_split(str, ' ');
	}
	if (str)
		free(str);
	return (split);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
