FLAGS = -Wall -Wextra -Werror
NAME = libft.a

LIBFT_SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c
LIBFT_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c 
GNL_SRCS = get_next_line_bonus.c get_next_line_utils_bonus.c
PRINTF_SRCS = ft_ctos.c ft_htos.c ft_printf.c ft_utos.c ft_stos.c ft_ptos.c
SRCS = $(LIBFT_SRCS:ft_%.c=libft/ft_%.c) $(LIBFT_BONUS:ft_%.c=libft/ft_%.c) $(PRINTF_SRCS) $(GNL_SRCS)
OBJS = $(LIBFT_SRCS:.c=.o) $(PRINTF_SRCS:.c=.o) $(LIBFT_BONUS:.c=.o) $(GNL_SRCS:.c=.o)



all: $(NAME)

$(NAME): 
	cc $(FLAGS) -c $(SRCS)
	ar rc  $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re