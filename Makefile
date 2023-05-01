# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wfan <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/23 14:49:13 by wfan              #+#    #+#              #
#    Updated: 2023/04/23 14:49:15 by wfan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB_PATH 	= libft/
LIB 		= $(LIB_PATH)libft.a
SRC = check_args \
operations_1 \
operations_2 \
operations_3 \
utils \
main \

OBJ = $(SRC:=.o)
NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -I. 
LDFLAGS 	= -L$(LIB_PATH) -lft 
DEBUGF 		= -fsanitize=address -g
RM = rm -rf

%.o:%.c
	$(CC) $(CFLAGS) -c $<

all : $(NAME)

$(NAME): $(LIB) $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) $(DEBUGF) -o $(NAME)

$(LIB):
	@make -C $(LIB_PATH) fclean && make -C $(LIB_PATH)

clean:
		$(RM) $(OBJ)
		make clean -C $(LIB_PATH)

fclean: clean
	$(RM) $(NAME) 
	make fclean -C $(LIB_PATH)

re: fclean all
.PHONY: clean fclean re norme all