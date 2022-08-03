SRCS =execute_shell.c \
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
	./lexer/fill_heredoc.c \
	./lexer/wild_cards.c \
	./exec/init_exec.c \
	./exec/execute.c \
	./exec/execute_ast.c \
	./exec/execute_utils.c \
	./builtins/execute_builtin.c \
	./builtins/export01.c \
	./builtins/export.c \
	./builtins/open_io_builtins.c \
	./builtins/unset.c \
	./builtins/cd.c \
	./builtins/exit01.c \
	./builtins/pwd.c \
	./builtins/echo.c \
	./builtins/env.c \
	./builtins/ft_getenv.c \
	./get_next_line/get_next_line_utils.c \
	./get_next_line/get_next_line.c
OBJS = $(SRCS:.c=.o)
CONTROL = @stty -echoctl
LFLAGS = -lreadline -L/Users/abelqasm/.brew/opt/readline/lib -I/Users/abelqasm/.brew/opt/readline/include
CC = cc
CFLAGS = -Werror -Wextra -Wall #-fsanitize=address -g
NAME = minishell
LIBFT = ./libft/libft.a

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	$(CONTROL)
	$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) $(LIBFT) minishell.c -o $(NAME)

$(LIBFT) :
	cd ./libft && make

clean :
	rm -rf $(OBJS)
	cd ./libft && make clean
	cd get_next_line && rm -rf *.o

fclean : clean
	rm -rf $(NAME)
	cd ./libft && make fclean

re : fclean all
