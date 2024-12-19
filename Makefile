# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/26 16:34:27 by yfradj            #+#    #+#              #
#    Updated: 2024/12/14 18:04:29 by yfradj           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

FLAGS = -Wall -Werror -Wextra

WAY = srcs/push_swap/
WAY_BONUS = srcs/checker/

SRCS = \
	$(WAY)arg_error.c \
	$(WAY)fct_utils.c \
	$(WAY)get_split.c \
	$(WAY)instruction.c \
	$(WAY)instruction2.c \
	$(WAY)instruction3.c \
	$(WAY)lst_utils.c \
	$(WAY)push_swap.c \
	$(WAY)sort_tab_index.c \
	$(WAY)sort_small_stack.c \
	$(WAY)sort.c

SRCS_BONUS = $(WAY_BONUS)arg_error_bonus.c \
	$(WAY_BONUS)checker_bonus.c \
	$(WAY_BONUS)fct_utils_bonus.c \
	$(WAY_BONUS)get_split_bonus.c \
	$(WAY_BONUS)instruction_bonus.c \
	$(WAY_BONUS)instruction2_bonus.c \
	$(WAY_BONUS)instruction3_bonus.c \
	$(WAY_BONUS)lst_utils_bonus.c \
	$(WAY_BONUS)read_execute_bonus.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
	
NAME = push_swap
NAME_BONUS = checker

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft --no-print-directory
	@$(CC) $(FLAGS) $(OBJS) libft/libft.a -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS)
	@make -C libft --no-print-directory
	@$(CC)  $(FLAGS) $(OBJS_BONUS) libft/libft.a -o $(NAME_BONUS)

bonus: $(NAME_BONUS)

clean:
	@make clean -C libft --no-print-directory
	@rm -f $(OBJS) $(OBJS_BONUS) 

fclean: clean
	@make fclean -C libft --no-print-directory
	@rm -f $(NAME) $(NAME_BONUS) 
	
re: fclean all

.PHONY: all fclean clean bonus re