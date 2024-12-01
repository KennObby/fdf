LIBFT = lib/Libft/ft_atoi.c \
	lib/Libft/ft_bzero.c \
	lib/Libft/ft_calloc.c \
	lib/Libft/ft_itoa.c \
	lib/Libft/ft_isalpha.c \
	lib/Libft/ft_isalnum.c \
	lib/Libft/ft_isascii.c \
	lib/Libft/ft_isdigit.c \
	lib/Libft/ft_isprint.c \
	lib/Libft/ft_memchr.c \
	lib/Libft/ft_memcmp.c \
	lib/Libft/ft_memcpy.c \
	lib/Libft/ft_memmove.c \
	lib/Libft/ft_memset.c \
	lib/Libft/ft_putchar_fd.c \
	lib/Libft/ft_putendl_fd.c \
	lib/Libft/ft_putnbr_fd.c \
	lib/Libft/ft_putstr_fd.c \
	lib/Libft/ft_split.c \
	lib/Libft/ft_strlcat.c \
	lib/Libft/ft_strlcpy.c \
	lib/Libft/ft_strlen.c \
	lib/Libft/ft_strnstr.c \
	lib/Libft/ft_strncmp.c \
	lib/Libft/ft_strchr.c \
	lib/Libft/ft_strrchr.c \
	lib/Libft/ft_strdup.c \
	lib/Libft/ft_strjoin.c \
	lib/Libft/ft_strtrim.c \
	lib/Libft/ft_strmapi.c \
	lib/Libft/ft_striteri.c \
	lib/Libft/ft_substr.c \
	lib/Libft/ft_toupper.c \
	lib/Libft/ft_tolower.c \
	lib/Libft/ft_lstnew_bonus.c \
	lib/Libft/ft_lstadd_front_bonus.c \
	lib/Libft/ft_lstsize_bonus.c \
	lib/Libft/ft_lstlast_bonus.c \
	lib/Libft/ft_lstadd_back_bonus.c \
	lib/Libft/ft_lstdelone_bonus.c \
	lib/Libft/ft_lstclear_bonus.c \
	lib/Libft/ft_lstiter_bonus.c \
	lib/Libft/ft_lstmap_bonus.c \
	lib/Libft/ft_printf.c \
	lib/libLibft/ft_putchar.c \
	lib/Libft/ft_putnbr.c \
	lib/Libft/ft_putunbr.c \
	lib/Libft/ft_putstr.c \
	lib/Libft/ft_putptr.c \
	lib/Libft/ft_puthex_lower.c \
	lib/Libft/ft_puthex_upper.c \
	lib/Libft/get_next_line_bonus.c

SRCS = src/main.c \
	src/parser.c \
	src/renderer.c \
	src/input_handler.c \
	src/utils.c

INC = -I includes/ -I lib/mlx/
LIBS = -L lib/mlx/ -lmlx -framework OpenGL -framework AppKit
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIB_OBJS = $(LIBFT:.c=.o)
SRCS_OBJS = $(SRCS:.c=.o)

NAME = fdf.a
AR = ar rcs
RM = rm -rf

all: $(NAME)

$(NAME): $(SRCS_OBJS) $(LIB_OBJS)
	$(AR) $(NAME) $(SRCS_OBJS) $(LIB_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	$(RM) $(LIB_OBJS) $(SRCS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

