# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hogkim <hogkim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/09 16:38:14 by hogkim            #+#    #+#              #
#    Updated: 2022/06/13 15:46:44 by hogkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
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
			  sort_5to100.c \
			  sort_5to100_find.c \
			  sort_5to100_utils.c \
			  stack.c \
			  utils.c 
OBJS		= $(SRCS:.c=.o)

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

clean :
	rm -rf $(OBJS) $(LIBFT)
	make -C libft clean

fclean :
	rm -rf $(OBJS) $(NAME) $(LIBFT)
	make -C libft fclean

re :
	make fclean
	make all

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^

$(LIBFT) :
	make -C libft
	cp libft/libft.a .

.PHONY : all clean fclean re