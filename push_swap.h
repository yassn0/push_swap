/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:45:43 by yfradj            #+#    #+#             */
/*   Updated: 2024/11/29 17:15:31 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct a_list
{
	int				nb;
	struct a_list	*next;
}					s_list;

int					error(void);
int					double_number(char **tab);
int					check_error2(char **tab);
int					check_error1(char **tab);
s_list				*ft_lstnew(int n);
void				ft_lstadd_front(s_list **lst, s_list *new);
void				ft_lstadd_back(s_list **lst, int n);
void				ft_lstadd_front(s_list **lst, s_list *new);
void				ft_lstclear(s_list **lst);
s_list				*ft_lstlast(s_list *lst);
int					ft_atoi_max(const char *str);
char				**get_split(int ac, char **av);
char				*create_str_for_split(int ac, char **av);
int					len_av(int ac, char **av);
void				print_list(s_list **lst);
int					lst_size(s_list **begin_lst);

void				sa(s_list **begin_la);
void				sb(s_list **begin_lb);
void				pa(s_list **begin_la, s_list **begin_lb);
void				pb(s_list **begin_la, s_list **begin_lb);
void				ra(s_list **begin_la);
void				rra(s_list **begin_la);
void				rra(s_list **begin_la);

#endif