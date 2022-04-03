SRCS = minishell.c \
	ft_check_argmt.c \
	ft_pipe_mngmt.c \
	ft_check_cmd.c

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
	cd ./libft && make re