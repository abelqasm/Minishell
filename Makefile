SRCS = minishell.c \
	./lexer/lexer.c \
	./lexer/token.c \
	./lexer/parser.c \
	./lexer/ast.c \
	./lexer/list.c \
	# ./exec/pipex/pipex_bonus.c \
	# ./exec/pipex/pipex_bonus_child.c \
	# ./exec/pipex/utils/ft_errors.c \
	# ./exec/pipex/utils/ft_close_pipes.c
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Werror -Wextra -Wall
NAME = minishell
LIBFT = ./libft/libft.a

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -lreadline $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT) :
	cd ./libft && make

clean :
	rm -rf $(OBJS)
	cd ./libft && make clean

fclean : clean
	rm -rf $(NAME)
	cd ./libft && make fclean

re : fclean all