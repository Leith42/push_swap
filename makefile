TARGET_PS = push_swap
TARGET_C = checker
CC = gcc
LIBFT_PATH = ./libft/
LIBFT_INCLUDE = $(LIBFT_PATH)include/
LIBFT_BIN = $(LIBFT_PATH)libft.a
INCLUDE = ./include/
HEADER = -I$(INCLUDE) -I$(LIBFT_INCLUDE)
CFLAGS = -Wall -Wextra -Werror $(HEADER)
SRC_PATH = ./src/
CHECKER_SRC = $(SRC_PATH)checker/
RM = rm -f

SRC = \
		$(SRC_PATH)advanced_operations.c \
		$(SRC_PATH)basic_operations.c \
		$(SRC_PATH)args_parsing.c \
		$(SRC_PATH)free_stack.c \
		$(SRC_PATH)ft_atol.c \
		$(SRC_PATH)printer.c \
		$(SRC_PATH)handle_args.c \
		$(SRC_PATH)handle_error.c \

PUSH_SWAP = \
		$(SRC_PATH)algo.c \
		$(SRC_PATH)push_swap.c \
		$(SRC_PATH)get_min.c \
		$(SRC_PATH)push_all_in_a.c \

CHECKER = \
		$(CHECKER_SRC)checker.c \
		$(CHECKER_SRC)instructions_parsing.c \

SRC_OBJ = $(SRC:.c=.o)
PUSH_SWAP_OBJ = $(PUSH_SWAP:.c=.o)
CHECKER_OBJ = $(CHECKER:.c=.o)

all: $(TARGET_PS) $(TARGET_C)

$(TARGET_PS): $(PUSH_SWAP_OBJ) $(SRC_OBJ)
	@make -C $(LIBFT_PATH)
	@$(CC) $(CFLAGS) $(PUSH_SWAP_OBJ) $(SRC_OBJ) -o $@ $(LIBFT_BIN)
	@echo "push_swap : compiled with success!"

$(TARGET_C): $(CHECKER_OBJ)
	@$(CC) $(CFLAGS) $(LIBFT_BIN) $(CHECKER_OBJ) $(SRC_OBJ) -o $@ $(LIBFT_BIN)
	@echo "checker : compiled with success!"

clean:
	@make -C $(LIBFT_PATH) clean
	@$(RM) $(PUSH_SWAP_OBJ) $(CHECKER_OBJ)
	@echo "objects removed."

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@$(RM) $(PUSH_SWAP_OBJ) $(CHECKER_OBJ)
	@$(RM) $(TARGET_C) $(TARGET_PS)
	@echo "./push_swap and ./checker removed."

re: fclean all

.PHONY: all clean fclean re
