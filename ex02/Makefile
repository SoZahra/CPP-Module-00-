# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fzayani <fzayani@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/05 15:36:43 by fzayani           #+#    #+#              #
#    Updated: 2025/02/05 15:39:35 by fzayani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = account

CC = c++

CFLAG = -Wall -Wextra -Wextra -std=c++98

SRC = Account.cpp tests.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): 	$(OBJ)
			$(CC) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAG) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean all