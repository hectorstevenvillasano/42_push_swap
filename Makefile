
LIB = libft/libft.a
NAMEPS = push_swap
NAMEC  = checker
FLAGS = -Wall -Wextra -Werror

SRC =	push_swap.c \
		freeit.c \
		create_stack.c \
		solver.c \
		struct.c \
		sort.c \
		sort2.c \
		rules.c \
		help.c \
		print.c \

all: $(NAMEPS)

$(NAMEPS): $(SRC)
	gcc -g $(FLAGS) $(SRC) $(LIB) -o $(NAMEPS)

re: fclean all
	#make re -C libft/
clean:
	#make clean -C libft/
fclean: clean
	#make fclean -C libft/
	rm $(NAMEPS)
