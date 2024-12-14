/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_execute_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 15:34:28 by yfradj            #+#    #+#             */
/*   Updated: 2024/12/14 16:59:06 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1)
		return (1);
	if (!s2 )
		return (1);
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}

void	execute(t_list **la, t_list **lb, char *line)
{
	if (ft_strcmp(line, "sa") == 0)
		sa(la);
	else if ((ft_strcmp(line, "sb\n") == 0))
		sb(lb);
	else if ((ft_strcmp(line, "ss\n") == 0))
	{
		sa(la);
		sb(lb);
	}
	else if ((ft_strcmp(line, "pa\n") == 0))
		pa(la, lb);
	else if ((ft_strcmp(line, "pb\n") == 0))
		pb(la, lb);
	else if ((ft_strcmp(line, "ra\n") == 0))
		ra(la);
	else if ((ft_strcmp(line, "rb\n") == 0))
		rb(lb);
	else if ((ft_strcmp(line, "rr\n") == 0))
		rr(la, lb);
	else if ((ft_strcmp(line, "rra\n") == 0))
		rra(la);
	else if ((ft_strcmp(line, "rrb\n") == 0))
		rrb(lb);
	else if ((ft_strcmp(line, "rrr\n") == 0))
		rrr(la, lb);
}

void	read_and_execute(t_list **la, t_list **lb)
{
	char	*line;

	while ((line = get_next_line(0)) != NULL)
	{
		execute(la, lb, line);
		if (line)
			free(line);
	}
}
