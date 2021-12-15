# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eassofi <eassofi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/20 18:58:34 by eassofi           #+#    #+#              #
#    Updated: 2021/12/15 21:33:45 by eassofi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = client server

SRV = minitalk_utils/src/server.c

CLT = minitalk_utils/src/client.c

CC = gcc

INC_DIR= ../include/lib.h

CFLAGS = -fsanitize=address -Wall -Wextra -Werror -I$(INC_DIR)

RM = rm -rf

LIB = minitalk_utils/lib/lib.a

all : $(NAME)

client : $(LIB)
		$(CC) $(CFLAGS) $(CLT) $(LIB) -o $@
server : $(LIB)
		$(CC) $(CFLAGS) $(SRV) $(LIB) -o $@
		
clean  : 
	    $(RM) $(NAME)

fclean : clean

re     : fclean all 
