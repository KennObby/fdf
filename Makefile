LIBFT_DIR = lib/Libft
LIBFT = $(LIBFT_DIR)/Libft.a 

SRCS = src/main.c \
       src/parsing/parser.c \
       src/parsing/parse_file.c \
       src/parsing/parser_utils.c \
       src/parsing/populate_map.c \
       src/parsing/read_lines.c \
       src/rendering/draw_line.c \
       src/rendering/project_and_draw.c \
       src/rendering/project_point.c \
       src/rendering/renderer.c \
       src/rendering/renderer_utils.c \
       src/events/input_handler.c \
	   src/events/mouse_handler.c \
       src/utils/utils.c 		\
	   src/utils/free.c

INC = -I inc/ -I lib/mlx/ -I lib/Libft
LIBS = -L lib/mlx -lmlx -L lib/Libft -lft -lm -lX11 -lXext
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS_OBJS = $(SRCS:.c=.o)

NAME = fdf
RM = rm -rf

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(SRCS_OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(SRCS_OBJS) -o $(NAME) $(LIBS)

%.o: %.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@make -C $(LIBFT_DIR) clean
	@$(RM) $(SRCS_OBJS)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
