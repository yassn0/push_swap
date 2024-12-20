/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:45:43 by yfradj            #+#    #+#             */
/*   Updated: 2024/12/14 17:09:38 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "../../libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				nb;
	int				s_index;
	struct s_list	*next;
}					t_list;

int					error(char **split);
int					double_number(char **tab);
int					check_error2(char **tab);
int					check_error1(char **tab);
int					ft_atoi_max(const char *str);

t_list				*ft_lstnew(int n);
void				ft_lstadd_back(t_list **lst, int n);
void				ft_lstclear(t_list **lst);
t_list				*ft_lstlast(t_list *lst);
int					lst_size(t_list **begin_lst);

char				**get_split(int ac, char **av);
char				*create_str_for_split(int ac, char **av);
int					len_av(int ac, char **av);

void				sa(t_list **begin_la);
void				sb(t_list **begin_lb);
void				pa(t_list **begin_la, t_list **begin_lb);
void				pb(t_list **begin_la, t_list **begin_lb);
void				ra(t_list **begin_la);
void				rb(t_list **begin_lb);
void				rra(t_list **begin_la);
void				rrb(t_list **begin_lb);
void				rr(t_list **la, t_list **lb);
void				rrr(t_list **la, t_list **lb);
void				ra_no_comment(t_list **begin_la);
void				rb_no_comment(t_list **begin_lb);
void				rra_no_comment(t_list **begin_la);
void				rrb_no_comment(t_list **begin_lb);

int					is_sorted(t_list **begin_list);
void				sort_three(t_list **begin_list);

int					special_case(t_list **la, char **split);
void				sort_two_or_one(t_list **la);
void				free_all(char **split, t_list **la);
void				free_tab(char **tab);

void				read_and_execute(t_list **la, t_list **lb);
void				execute(t_list **la, t_list **lb, char *line);

#endif