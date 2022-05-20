SRCS =  ft_strlen.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isprint.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_memset.c \
		ft_isascii.c \
		ft_memcpy.c \
		ft_bzero.c \
		ft_memmove.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_realloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_lstlast.c

OBJS = $(SRCS:.c=.o)
CC = gcc -Wall -Werror -Wextra -c

NAME = libft.a
all: $(NAME)

$(NAME) : $(OBJS)
	${CC} $(SRCS) 
	ar -rc $(NAME) $(OBJS)
clean :
	rm -rf *.o

fclean : clean
	rm -f $(NAME)

re : fclean all