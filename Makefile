NAME = pipex.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

FILES = get_path.c 
SRCS = $(FILES)
OBJS = $(SRCS:.c=.o)

all: $(NAME)
	cd libft && $(MAKE)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS) && cd libft && $(MAKE) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re