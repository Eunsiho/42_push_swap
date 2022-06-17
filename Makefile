# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hogkim <hogkim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/09 16:38:14 by hogkim            #+#    #+#              #
#    Updated: 2022/06/17 09:47:26 by hogkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
BONUS		= checker
LIBFT		= libft.a

SRCS		= commands.c \
			  parsing.c \
			  parsing2.c \
			  push_swap.c \
			  rules1.c \
			  rules2.c \
			  rules3.c \
			  sort_and_print.c \
			  sort_utils.c \
			  sort_3to5.c \
			  sort_over5.c \
			  stack.c \
			  utils.c 
OBJS		= $(SRCS:.c=.o)
SRCS_B		= checker.c \
			  checker_rules1.c \
			  checker_rules2.c \
			  checker_rules3.c \
			  commands.c \
			  parsing.c \
			  parsing2.c \
			  stack.c \
			  sort_utils.c \
			  utils.c  
OBJS_B		= $(SRCS_B:.c=.o)

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

bonus : $(BONUS)

clean :
	rm -rf $(OBJS) $(OBJS_B) $(LIBFT) 
	make -C libft clean

fclean :
	rm -rf $(OBJS) $(NAME) $(OBJS_B) $(LIBFT) $(BONUS)
	make -C libft fclean

re :
	make fclean
	make all

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^

$(LIBFT) :
	make -C libft
	cp libft/libft.a .

$(BONUS) : $(OBJS_B) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^

.PHONY : all clean fclean re bonus