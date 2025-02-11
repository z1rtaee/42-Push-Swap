###COLOURS###
PINK 	= \e[1;35m
PURPLE	= \e[0;95m
WHITE   = \e[1;37m
DEFAULT = \e[0m

###VARIABLES###
NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRC_DIR = src/
LIBFT_DIR = Libft/
INCLUDE = ./Libft/libft.a

SRCS = $(SRC_DIR)parsing.c $(SRC_DIR)main.c $(SRC_DIR)stack_utils.c \
$(SRC_DIR)memory_handle.c $(SRC_DIR)operations.c $(SRC_DIR)sort_utils.c \
$(SRC_DIR)swap_push_moves.c $(SRC_DIR)rotate_revotate_moves.c

OBJS = $(SRCS:.c=.o)

###RULES###
%.o: %.c
	@$(CC) $(CFLAGS) -c $(<) -o $(@)

$(NAME): $(OBJS)
	@echo "$(WHITE)Bringing $(PINK)$(NAME)$(WHITE) to life!$(DEFAULT)"
	@make -s -C $(LIBFT_DIR)
	@echo "$(WHITE)Creating $(PINK)$(NAME)'s$(WHITE) executable...$(DEFAULT)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(INCLUDE)
	@echo "$(PINK)$(NAME) was born!$(DEFAULT)"

all: $(NAME)

clean:
	@make -s -C $(LIBFT_DIR) clean 
	@rm -rf $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re