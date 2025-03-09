### COLOURS ###
PINK 	= \e[1;35m
PURPLE	= \e[0;95m
WHITE   = \e[1;37m
DEFAULT = \e[0m

### VARIABLES ###
NAME			= push_swap

CC				= cc
CFLAGS			= -Wall -Wextra -Werror -g

SRCS	 		= $(SRC_DIR)parsing.c $(SRC_DIR)main.c $(SRC_DIR)stack_utils.c \
				$(SRC_DIR)memory_handle.c $(SRC_DIR)operations.c $(SRC_DIR)sort_utils.c \
				$(SRC_DIR)swap_push_moves.c $(SRC_DIR)rotate_revotate_moves.c \
				$(SRC_DIR)a_cheapest_node.c $(SRC_DIR)b_cheapest_node.c \
				$(SRC_DIR)a_algorithm.c $(SRC_DIR)b_algorithm.c 
SRC_DIR			= src/

OBJS 			= $(SRCS:%.c=%.o)

### COMPLETE LIB ###
LIBFT_PATH		= complete_lib/42_Libft/
LIBFT			= $(LIBFT_PATH)libft.a
FT_PRINTF_PATH	= complete_lib/42_Printf/
FT_PRINTF		= $(FT_PRINTF_PATH)libftprintf.a
GNL_PATH		= complete_lib/42_GNL/
GNL				= $(GNL_PATH)libgnl.a
PERSONAL_LIBS	=	-lft -lgnl -lftprintf

INCLUDE			= -I inc/

### RULES ###
%.o: 			%.c
				@$(CC) $(CFLAGS) -c $(<) -o $(@)

all: 			$(NAME)

$(NAME): 		$(OBJS) $(LIBFT) $(FT_PRINTF) $(GNL)
				@echo "$(WHITE)Bringing $(PINK)$(NAME)$(WHITE) to life!$(DEFAULT)"
				@echo "$(WHITE)Creating $(PINK)$(NAME)'s$(WHITE) executable...$(DEFAULT)"
				@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_PATH) -L$(FT_PRINTF_PATH) -L$(GNL_PATH) $(PERSONAL_LIBS) -o $(NAME) 
				@echo "$(PINK)$(NAME) was born!$(DEFAULT)"

$(LIBFT):
				@make -s -C $(LIBFT_PATH)

$(FT_PRINTF):
				@make -s -C $(FT_PRINTF_PATH)

$(GNL):
				@make -s -C $(GNL_PATH)

### CLEAN RULES ###
clean:
				@make -s -C $(LIBFT_PATH) clean
				@make -s -C $(FT_PRINTF_PATH) clean
				@make -s -C $(GNL_PATH) clean
				@rm -rf $(OBJS)
				@echo "$(WHITE)Object files cleaned$(DEFAULT)"

fclean: 		clean
				@make -s -C $(LIBFT_PATH) fclean
				@make -s -C $(FT_PRINTF_PATH) fclean
				@make -s -C $(GNL_PATH) fclean
				@rm -f $(NAME)
				@echo "$(WHITE)Executable cleaned$(DEFAULT)"

re: 			fclean all

.PHONY: 		all clean fclean re $(LIBFT) $(FT_PRINTF) $(GNL)