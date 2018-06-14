# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghaddad <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/14 09:08:19 by ghaddad           #+#    #+#              #
#    Updated: 2018/06/14 09:08:26 by ghaddad          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP =			push_swap
CHECKER =			checker
NAME = 				$(PUSH_SWAP) $(CHECKER)
LIBFT_A = 			libft.a

CC =				gcc
CFLAGS =			-Wall -Wextra -Werror -c

PUSH_SWAP_H =		-I includes/
LIBFT_PATH =		libft/

OBJ_PATH =			obj/
PUSH_OBJ_PATH =		obj/push_swap/
SHARED_OBJ_PATH = 	obj/shared/
CHECK_OBJ_PATH =	obj/checker/
PUSH_PATH =			srcs/push_swap/
SHARED_PATH =		srcs/shared/
CHECK_PATH =		srcs/checker/

PUSH_SRC_NAME =		algo.c \
					arrange_b.c \
					arrange_b_bis.c \
					calc_median.c \
					maxmin.c \
					push_swap.c \
					simplify_operations.c \
					swap_solver.c

CHECK_SRC_NAME =	checker.c \
					do_operations.c \
					get_next_line.c \
					read_output.c

SHARED_SRC_NAME =	add_text.c \
					create_stack.c \
					do_push.c \
					do_reverse_rotate.c \
					do_rotate.c \
					do_swap.c \
					intmaxatoi.c \
					sorted_stack.c

PUSH_SRC =			$(addprefix $(PUSH_PATH), $(PUSH_SRC_NAME))
CHECK_SRC = 		$(addprefix $(CHECK_PATH), $(CHECK_SRC_NAME))
SHARED_SRC =		$(addprefix $(SHARED_PATH), $(SHARED_SRC_NAME))

PUSH_OBJ =			$(patsubst %.c, $(PUSH_OBJ_PATH)%.o, $(PUSH_SRC_NAME))
CHECK_OBJ =			$(patsubst %.c, $(CHECK_OBJ_PATH)%.o, $(CHECK_SRC_NAME))
SHARED_OBJ =		$(patsubst %.c, $(SHARED_OBJ_PATH)%.o, $(SHARED_SRC_NAME))
OBJ =				$(PUSH_OBJ) $(CHECK_OBJ) $(SHARED_OBJ)

all: $(NAME)

comp_lib:
					@make -C $(LIBFT_PATH)

$(PUSH_OBJ_PATH):
					@mkdir -p $(PUSH_OBJ_PATH)
$(SHARED_OBJ_PATH):
					@mkdir -p $(SHARED_OBJ_PATH)
$(CHECK_OBJ_PATH):
					@mkdir -p $(CHECK_OBJ_PATH)

$(PUSH_OBJ_PATH)%.o: $(PUSH_PATH)%.c
					@$(CC) $(CFLAGS) $< -o $@ $(PUSH_SWAP_H)
$(SHARED_OBJ_PATH)%.o: $(SHARED_PATH)%.c
					@$(CC) $(CFLAGS) $< -o $@ $(PUSH_SWAP_H)
$(CHECK_OBJ_PATH)%.o: $(CHECK_PATH)%.c
					@$(CC) $(CFLAGS) $< -o $@ $(PUSH_SWAP_H)

$(OBJ_PATH):
					@mkdir -p $(OBJ_PATH)
					@mkdir -p $(PUSH_OBJ_PATH) $(CHECK_OBJ_PATH) $(SHARED_OBJ_PATH)

$(NAME): comp_lib $(PUSH_OBJ_PATH) $(PUSH_OBJ) $(SHARED_OBJ_PATH) $(SHARED_OBJ) $(CHECK_OBJ_PATH) $(CHECK_OBJ)
					@$(CC) $(PUSH_OBJ) $(SHARED_OBJ) $(PUSH_SWAP_H) $(LIBFT_PATH)$(LIBFT_A) \
							-o $(PUSH_SWAP)
					@echo "~~~push_swap successfully created !~~~"
					@$(CC) -g -fsanitize=address $(CHECK_OBJ) $(SHARED_OBJ) $(PUSH_SWAP_H) $(LIBFT_PATH)$(LIBFT_A) \
							-o $(CHECKER)
					@echo "~~~checker successfully created !~~~"

clean:
					@make -C $(LIBFT_PATH) clean
					@rm -rf $(OBJ_PATH)
					@echo "~~~Clean successful !~~~"

fclean: clean
					@make -C $(LIBFT_PATH) fclean
					@rm $(PUSH_SWAP) $(CHECKER)
					@echo "~~~Fclean successful~~~"

re: fclean all

.PHONY: all clean flcean re