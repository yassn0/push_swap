/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yassinfradj28@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:45:43 by yfradj            #+#    #+#             */
/*   Updated: 2024/12/04 17:59:57 by yfradj           ###   ########.fr       */
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
void				rb(s_list **begin_lb);
void				rra(s_list **begin_la);
void				rrb(s_list **begin_lb);
int					is_sorted_dec(s_list **begin_list);
int					is_sorted(s_list **begin_list);
int					calcul_index(s_list **begin_list, int n);
int					closer_to_the_beginning_or_the_end(s_list **begin_list,
						int n);
int					cost_sort_lb_for_pb(s_list **lb, int n);
int					calcul_cost(s_list **begin_la, s_list **begin_lb, int n);
int					find_max(s_list **begin_lst);
int					find_target_index(s_list **begin_lst, int target);
void				sort_stack_b(s_list **begin_lb);
int					n_min_cost(s_list **begin_la, s_list **begin_lb);
int					move_to_position_b(s_list **begin_lb, int n);
int					move_to_top_a(s_list **begin_la, int nb_min_cost);

#endif