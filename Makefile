# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/27 12:28:32 by jpirsch           #+#    #+#              #
#    Updated: 2016/02/27 12:44:55 by jpirsch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

export FLAGS		= -Wall -Wextra -Werror
SRC_DIR			= ./sources
LIB_DIR			= ./libft

all:
	make -C $(LIB_DIR)
	make -C $(SRC_DIR)

clean:
	make -C $(LIB_DIR) clean
	make -C $(SRC_DIR) clean

fclean: clean
	make -C $(LIB_DIR) fclean
	make -C $(SRC_DIR) fclean

re: fclean all
