# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hvillasa <hvillasa@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/27 01:24:47 by hvillasa          #+#    #+#              #
#    Updated: 2017/05/27 23:51:18 by hvillasa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = libft/libft.a
NAMEPS = push_swap
NAMEC  = checker
FLAGS = -Wall -Wextra -Werror

PS_SRC	=	push_swap.c \
			freeit.c \
			create_stack.c \
			struct.c \
			sort.c \
			sort2.c \
			rules.c \
			help.c \
			print.c \

C_SRC =		checker.c \
			freeit.c \
			create_stack.c \
			struct.c \
			sort.c \
			sort2.c \
			rules.c \
			help.c \
			print.c \

all: $(NAMEPS) $(NAMEC)

$(NAMEPS): $(PS_SRC)
	@make -C libft/
	gcc $(FLAGS) $(PS_SRC) $(LIB) -o $(NAMEPS)

$(NAMEC): $(C_SRC)
	@make -C libft/
	gcc $(FLAGS) $(C_SRC) $(LIB) -o $(NAMEC)

re: fclean all
	@make re -C libft/
clean:
	@make clean -C libft/
fclean: clean
	@make fclean -C libft/
	rm $(NAMEPS)
	rm $(NAMEC)
