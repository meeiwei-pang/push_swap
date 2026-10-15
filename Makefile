# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmeei-we <pmeei-we@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/14 12:07:53 by ibishak           #+#    #+#              #
#    Updated: 2026/10/15 15:10:22 by pmeei-we         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -I$(LIBFT_DIR)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

HEADERS = push_swap.h

SRC_DIR	= srcs
OBJ_DIR	= obj

SRCS = $(SRC_DIR)/operations/ops_push.c \
	$(SRC_DIR)/operations/ops_swap.c \
	$(SRC_DIR)/operations/ops_rotate.c \
	$(SRC_DIR)/operations/ops_rotate_reverse.c \
	$(SRC_DIR)/operations/ops_utils.c \
	$(SRC_DIR)/sorting/select_sort.c \
	$(SRC_DIR)/sorting/sort_adaptive.c \
	$(SRC_DIR)/sorting/sort_small.c \
	$(SRC_DIR)/sorting/sort_simple.c \
	$(SRC_DIR)/sorting/sort_medium.c \
	$(SRC_DIR)/sorting/sort_complex.c \
	$(SRC_DIR)/sorting/sort_utils.c \
	$(SRC_DIR)/stack/stack_init.c \
	$(SRC_DIR)/stack/stack_list.c \
	$(SRC_DIR)/stack/stack_parsing.c \
	$(SRC_DIR)/stack/stack_analysis.c \
	$(SRC_DIR)/stack/stack_utils.c \
	$(SRC_DIR)/bench/bench_stats.c \
	$(SRC_DIR)/main.c


OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MAIN) $(LIBFT) -o $(NAME)
	
clean:
	rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re