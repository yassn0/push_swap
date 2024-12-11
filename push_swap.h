/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:45:43 by yfradj            #+#    #+#             */
/*   Updated: 2024/12/11 16:49:34 by yfradj           ###   ########.fr       */
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

int					error(char **split);
int					double_number(char **tab);
int					check_error2(char **tab);
int					check_error1(char **tab);
int					ft_atoi_max(const char *str);

s_list				*ft_lstnew(int n);
void				ft_lstadd_front(s_list **lst, s_list *new);
void				ft_lstadd_back(s_list **lst, int n);
void				ft_lstclear(s_list **lst);
s_list				*ft_lstlast(s_list *lst);

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
void				rr(s_list **la, s_list **lb);
void				rrr(s_list **la, s_list **lb);
void				ra_no_comment(s_list **begin_la);
void				rb_no_comment(s_list **begin_lb);
void				rra_no_comment(s_list **begin_la);
void				rrb_no_comment(s_list **begin_lb);

int					is_sorted_dec(s_list **begin_list);
int					is_sorted(s_list **begin_list);
int					calcul_index(s_list **lb, int n);
int					closer_to_the_beginning_or_the_end(s_list **begin_list,
						int n);
int					cost_sort_lb_for_pb(s_list **lb, int n);
int					calcul_cost(s_list **begin_la, s_list **begin_lb, int n);
int					n_min_cost(s_list **begin_la, s_list **begin_lb);
int					prepare_lb(s_list **lb, int n);
void				go_back(s_list **lb, int back);
void				move_to_top_a(s_list **begin_la, int nb_min_cost);
void				sort_three(s_list **begin_list);
void				sort_three_dec(s_list **begin_list);

void				ft_algo(s_list **la, s_list **lb, int size);
void				ft_algo1(s_list **la, s_list **lb);
void				ft_algo2(s_list **la, s_list **lb, int size);
int					special_case(s_list **la, char **split);
void				sort_two_or_one(s_list **la);
void				free_all(char **split, s_list **la);
void				free_tab(char **tab);

int					count_to_top_a(s_list **begin_la, int nb_min_cost);
int					count_prepare_lb(s_list **lb, int n);
int					rrr_rr_possible(s_list **la, s_list **lb, int nb_min_cost);

int					ft_min(s_list *la);

#endif