SRCS = minishell.c \
	execute_shell.c \
	./lexer/lexer.c \
	./lexer/token.c \
	./lexer/token_id.c \
	./lexer/token_quotes.c \
	./lexer/fill_struct.c \
	./lexer/parser.c \
	./lexer/ast.c \
	./lexer/utils.c \
	./lexer/list.c \
	./lexer/redirect.c \
	./lexer/parse_parenth.c \
	./exec/init_exec.c \
	./exec/execute.c \
	./exec/execute_ast.c \
	# ./exec/pipex/pipex_bonus.c \
	# ./exec/pipex/pipex_bonus_child.c \
	# ./exec/pipex/utils/ft_errors.c \
	# ./exec/pipex/utils/ft_close_pipes.c
OBJS = $(SRCS:.c=.o)
LFLAGS = -lreadline
CC = cc
CFLAGS = -Werror -Wextra -Wall #-fsanitize=address -g
NAME = minishell
LIBFT = ./libft/libft.a

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) $(LIBFT) -o $(NAME)

$(LIBFT) :
	cd ./libft && make

clean :
	rm -rf $(OBJS)
	cd ./libft && make clean

fclean : clean
	rm -rf $(NAME)
	cd ./libft && make fclean

re : fclean all
