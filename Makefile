SRC = get_next_line.c \
	  get_next_line_utils.c \
	  line_count.c \
	  line_count1.c \
	  map_init.c \
	  player_movment.c \
	  so_long.c \
	  struct_check.c \
	  image_maker.c \
	  ptf/ft_printf.c \
	  ptf/zy_argscheck.c \
	  ptf/zy_putnbr.c \
	  ptf/zy_putchar.c \
	  ptf/zy_putnbru.c \
	  ptf/zy_putstr.c \
	  ptf/zy_puthexa.c \

GCC = cc

NAME = so_long
OBJ = $(%.o : %.c)
all: $(NAME)

$(NAME): $(SRC)
	@gcc $(SRC) -Wall -Werror -Wextra -lmlx -framework OpenGL -framework Appkit -o $(NAME)
	@echo "\033[1;32m so_long is ready"

clean: 
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
re: fclean all