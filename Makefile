LIBFT_DIR = lib/Libft
LIBFT = $(LIBFT_DIR)/Libft.a 

SRCS = src/main.c \
       src/parser/parser.c \
       src/parser/parse_file.c \
       src/parser/parser_utils.c \
       src/parser/populate_map.c \
       src/parser/read_lines.c \
       src/renderer/draw_line/draw_line.c \
       src/renderer/project_and_draw/project_and_draw.c \
       src/renderer/renderer.c \
       src/renderer/renderer_utils.c \
       src/input/input_handler.c \
       src/utils/utils.c

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
