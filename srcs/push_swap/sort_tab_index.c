/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tab_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:35:56 by yfradj            #+#    #+#             */
/*   Updated: 2024/12/14 13:33:42 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*get_list_in_tab(t_list *la, int size_a)
{
	int		*tab;
	t_list	*current;
	int		i;

	i = 0;
	current = la;
	tab = (int *)malloc(size_a * sizeof(int));
	if (!tab)
		return (NULL);
	current = la;
	while (i < size_a)
	{
		tab[i] = current->nb;
		current = current->next;
		i++;
	}
	return (tab);
}

void	sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	assign_indices(t_list *la, int *sort_tab, int size)
{
	t_list	*current;
	int		i;

	current = la;
	while (current)
	{
		i = 0;
		while (i < size)
		{
			if (current->nb == sort_tab[i])
			{
				current->s_index = i;
				break ;
			}
			i++;
		}
		current = current->next;
	}
	free(sort_tab);
}

void	put_index(t_list **la)
{
	int	size;
	int	*tab;

	size = lst_size(la);
	tab = get_list_in_tab(*la, size);
	if (!tab)
		return ;
	sort_int_tab(tab, size);
	assign_indices(*la, tab, size);
}
