# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jomeirin <jomeirin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/25 11:32:01 by jomeirin          #+#    #+#              #
#    Updated: 2017/04/17 21:11:58 by aazri            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHEC=checker

PUSH=push_swap

CC=gcc

CFLAGS=-Wall -Wextra -Werror -g

RM=rm -f

INC_LIBFT= -L./libft -lft -Ilibft

FCLEAN_LIB=make -C libft/ fclean

PATH_SRC= ./src/

PATH_HD= -I includes/

SRC1 = $(PATH_SRC)checker.c $(PATH_SRC)printing.c $(PATH_SRC)stack_ops_adv.c $(PATH_SRC)stack_ops_basic.c
SRC2 = $(PATH_SRC)push_swap.c $(PATH_SRC)printing.c $(PATH_SRC)stack_ops_adv.c $(PATH_SRC)stack_ops_basic.c

OBJ1 = checker.o printing.o stack_ops_adv.o stack_ops_basic.o
OBJ2 = push_swap.o printing.o stack_ops_adv.o stack_ops_basic.o

$(CHEC):
	@echo "Compiling binaries..."
	@make re -C libft/
	@$(CC) $(CFLAGS) $(PATH_HD) -c $(SRC1)
	@$(CC) -o $(CHEC) $(OBJ1) -lm $(INC_LIBFT)
	@echo "*********Compilation was successful!**********"

$(PUSH):
	@$(CC) $(CFLAGS) $(PATH_HD) -c $(SRC2)
	@$(CC) -o $(PUSH) $(OBJ2) -lm $(INC_LIBFT)
	@echo ">>>>>>>Compilation was successful!<<<<<<<<"


all: $(CHEC) $(PUSH)

x11:
	@echo "Compiling binaries..."
	@make re -C libft/
	@$(CC) $(CFLAGS) $(PATH_HD) -c $(SRC)
	@$(CC) -o $(NAME) $(OBJ) -lm $(INC_LIBFT)
	@echo "Compilation was successful!------^^&^&^"

clean:
	@echo "Cleaning object files..."
	@$(RM) $(OBJ)
	@echo "Cleaning libft object files..."
	#@make -C libft/ clean
	@echo "Done cleaning!"
fclean:
	@echo "Cleaning object files..."
	@$(RM) $(OBJ1) $(OBJ2)
	@echo "Cleaning libft object & binary files..."
	#@make -C libft/ fclean
	@echo "Cleaning binaries..."
	@$(RM) $(CHEC) $(PUSH)
	@echo "Done cleaning!"

norme:
	@clear
	@norminette $(SRC)

re: fclean all
