# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/30 17:48:56 by dkurcbar          #+#    #+#              #
#    Updated: 2023/09/21 17:33:55 by dkurcbar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=   push_swap

	#libft Variables
LIBFT		=	./ft_libft/libft.a
LIBFT_DIR	=	./ft_libft

	# Mandatory Variables #
SRC	=	push_swap.c

CC		:=	gcc
CFLAG	:=	-Wall -Werror -Wextra
AR		:=	ar rcs
RM		:=	rm -f
MODE	:=	normal
INC		=	-I$(LIBFT_DIR) -L$(LIBFT_DIR) -lft
DEBUG   =

ifeq ($(MODE),debug)
	CFLAG	+=	-g
	DEBUG 	+=  MODE=debug
endif

all: 
	@ $(MAKE) --no-print-directory bonus $(DEBUG) -C $(LIBFT_DIR) 
	@ $(MAKE) --no-print-directory $(NAME)


$(NAME): $(LIBFT) $(SRC) Makefile 
	@ $(CC) $(CFLAG) $(SRC) $(INC) -o $(NAME)
	@printf "$(_SUCCESS) Push_swap ready.\n"

$(LIBFT): 
	@ $(MAKE) bonus -C  $(LIBFT_DIR)

clean:
	@ $(MAKE) --no-print-directory clean -C $(LIBFT_DIR)
	@ $(RM) $(NAME) 
	@printf "$(_INFO) push_swap removed.\n"


fclean: clean
	@ $(MAKE) --no-print-directory fclean -C $(LIBFT_DIR)
	@ $(RM) $(NAME) 
	@printf "$(_INFO)push_swap removed.\n"

re:	fclean all

.PHONY: all clean fclean re

