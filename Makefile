
LIB = "ft_printf/libftprintf.a"
NAMEPS = push_swap
FLAGS = -Wall -Wextra -Werror

SRC =	push_swap.c \
		freeit.c \
		create_stack.c \
		solver.c \
		struct.c \
		sort.c \


all: $(SRC)
	gcc -g $(FLAGS) $(SRC) $(LIB) -o $(NAMEPS)

re:fclean all

clean:

fclean: clean
		rm $(NAMEPS)
