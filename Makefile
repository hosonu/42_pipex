NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror

FILES = main.c comands.c libft/ft_split.c libft/ft_strjoin.c libft/ft_strncmp.c libft/ft_strlcat.c libft/ft_strlcpy.c libft/ft_strlen.c libft/ft_substr.c libft/ft_strdup.c
SRCS = $(FILES)
OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re