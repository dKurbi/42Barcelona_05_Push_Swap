# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/30 17:48:56 by dkurcbar          #+#    #+#              #
#    Updated: 2023/10/05 14:33:59 by dkurcbar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=   push_swap
BONUS	=	checker

	#libft Variables
LIBFT		=	./ft_libft/libft.a
LIBFT_DIR	=	./ft_libft

	# Mandatory Variables #
SRCS_M 	= push_swap.c
SRCS	= push_swap_utils_stack.c push_swap_utils_push.c \
		push_swap_utils_reverse_rotate.c push_swap_utils_rotate.c \
		push_swap_utils_swap.c push_swap_utils_sort.c \
		push_swap_utils_stack_2.c push_swap_utils_is.c push_swap_utils_args.c\
		push_swap_utils_get.c push_swap_utils_to_do.c push_swap_utils_is_2.c \
		push_swap_utils_calcs.c push_swap_utils_calcs_2.c \
		push_swap_utils_sort_2.c push_swap_utils_to_do_2.c \
		push_swap_utils_others.c 
		
		
SRCS_B	= checker.c push_swap_utils_cmd_lst_bonus.c \
		push_swap_utils_others_bonus.c push_swap_utils_get_bonus.c\
		push_swap_utils_to_do_bonus.c push_swap_utils_rotate_bonus.c \
		push_swap_utils_reverse_rotate_bonus.c push_swap_utils_push_bonus.c \
		push_swap_utils_swap_bonus.c
			
OBJS_M	:=	${SRCS_M:.c=.o}
OBJS	:=	${SRCS:.c=.o}
OBJS_B	:= 	${SRCS_B:.c=.o}
CC		:=	gcc
CFLAG	:=	-Wall -Werror -Wextra
AR		:=	ar rcs
RM		:=	rm -f
MODE	:=	normal
INC_LIB	:=	-I$(LIBFT_DIR) -L$(LIBFT_DIR) -lft
DEBUG   :=
INCLUDE :=  push_swap.h Makefile  
ifeq ($(MODE),debug)
	CFLAG	+=	-g
	DEBUG 	+=  MODE=debug
endif

all: 
	@ $(MAKE) --no-print-directory $(DEBUG) -C $(LIBFT_DIR) 
	@ $(MAKE) --no-print-directory $(NAME)

bonus: 
	@ $(MAKE) --no-print-directory $(DEBUG) -C $(LIBFT_DIR)
	@ $(MAKE) --no-print-directory $(BONUS)
	
$(BONUS):	$(OBJS) $(OBJS_M) $(OBJS_B) $(LIBFT) $(INCLUDE) $(NAME)
	@ $(CC) $(CFLAG) $(OBJS) $(OBJS_B) $(INC_LIB) -o $(BONUS)
	@printf "$(_SUCCESS) Bonus ready.\n"
	
$(NAME): $(OBJS) $(OBJS_M) $(LIBFT) $(INCLUDE)
	@ $(CC) $(CFLAG) $(OBJS) $(OBJS_M) $(INC_LIB) -o $(NAME)
	@printf "$(_SUCCESS) Push_swap ready.\n"

%.o: %.c ${INCLUDE}
	@${CC} -c $(CFLAG) $< -o $@ && echo "Compiled: $< -> $@"

$(LIBFT): 
	@ $(MAKE) bonus -C  $(LIBFT_DIR)

clean:
	@ $(MAKE) --no-print-directory clean -C $(LIBFT_DIR)
	@ ${RM} ${SRCS:.c=.o} ${SRCS_B:.c=.o} ${SRCS_M:.c=.o}
	@$(foreach obj,${OBJS},echo "File deleted: ${obj}";)
	@ $(foreach obj,${OBJS_M},echo "File deleted: ${obj}";)
	@ $(foreach obj,${OBJS_B},echo "File deleted: ${obj}";)

fclean: 
	@ $(MAKE) --no-print-directory fclean -C $(LIBFT_DIR)
	@ ${RM} ${SRCS:.c=.o} ${SRCS_B:.c=.o} ${SRCS_M:.c=.o}
	@ $(foreach obj,${OBJS},echo "File deleted: ${obj}";)
	@ $(foreach obj,${OBJS_M},echo "File deleted: ${obj}";)
	@ $(foreach obj,${OBJS_B},echo "File deleted: ${obj}";)
	@ $(RM) $(NAME) 
	@ $(RM) $(BONUS)
	@printf "$(_INFO)push_swap & bonus removed.\n"

re:	fclean all

.PHONY: all clean fclean re 

