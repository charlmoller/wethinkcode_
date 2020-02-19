# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ashulha <ashulha@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/14 11:54:02 by ashulha           #+#    #+#              #
#    Updated: 2017/07/14 11:56:14 by ashulha          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = easyfind

FILE = main.cpp

CCFLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@clang++ $(CCFLAG) $(FILE) -o $(NAME)

clean:

fclean: clean
	@rm -rf $(NAME)

re: fclean all
