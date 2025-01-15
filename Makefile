###COLOURS###
PINK 	= \e[1;35m
PURPLE 	= \e[0;95m
WHITE   = \e[1;37m
DEFAULT = \e[0m

###VARIABLES###
NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRC_DIR = src/
LIBFT_DIR = Libft/
INCLUDE = ./libft/libft.a

SRCS = $(SRC_DIR)main.c
OBJS = $(SRCS: .c=.o)

###RULES###
%.o: %.c
	$(CC) $(CFLAGS) -c $(<) -o $(@)

$(NAME): $(OBJS)
	@echo "$(PINK)Bringing $(PURPLE)$(NAME)$(PINK) to life!$(DEFAULT)"
	@make -C $(LIBFT_DIR)
	@echo "$(PINK)Creating $(PURPLE)$(NAME)'s$(PINK) executable$(DEFAULT)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(INCLUDE)
	@echo "$(PURPLE)$(NAME) was born!"

all: $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re