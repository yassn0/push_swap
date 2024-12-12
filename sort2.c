/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:35:56 by yfradj            #+#    #+#             */
/*   Updated: 2024/12/12 16:39:20 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*get_unique_values(s_list *la, int *length)
{
	int		*tab;
	s_list	*current;
	int		i;

	i = 0;
	current = la;
	*length = lst_size(&current);
	tab = (int *)malloc(*length * sizeof(int));
	if (!tab)
		return (NULL);
	// Remplir le tableau avec des valeurs uniques
	current = la;
	for (i = 0; i < *length; i++)
	{
		tab[i] = current->nb;
		current = current->next;
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

void	assign_indices(s_list *la, int *sorted_values, int length)
{
	s_list	*current;
	int		i;

	current = la;
	while (current)
	{
		i = 0;
		while (i < length)
		{
			if (current->nb == sorted_values[i])
			{
				current->s_index = i;
				break ;
			}
			i++;
		}
		current = current->next;
	}
	free(sorted_values);
}

void	put_index(s_list **la)
{
	int	size;
	int	*sorted_values;

	sorted_values = get_unique_values(*la, &size);
	if (!sorted_values)
		return ;
	sort_int_tab(sorted_values, size);
	assign_indices(*la, sorted_values, size);
}
