NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror

FILES = 
OBJS = $(SRCS:.c=.o)
SRCS = $(FILES)

all: $(NAME)
	cd libft && $(MAKE)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re