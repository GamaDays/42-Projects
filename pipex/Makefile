CC = cc -Wall -Werror -Wextra -fsanitize=address
NAME = pipex
SRC = pipex.c
OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ) ./libs/libft/libft.a
	$(CC) $(OBJ) ./libs/libft/libft.a -o $(NAME)

etest:
	$(CC) envp-test.c -o test

ftest:
	$(CC) fork-test.c -o test 

libft.a:
	make -C ./libs/libft/

fclean: clean
	rm -f $(NAME) test

clean: 
	rm -f $(OBJ)

re: fclean all

.Phony: all clean fclean re