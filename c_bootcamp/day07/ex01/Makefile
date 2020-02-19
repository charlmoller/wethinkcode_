# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ashulha <ashulha@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/12 16:43:03 by ashulha           #+#    #+#              #
#    Updated: 2017/07/12 17:27:21 by ashulha          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = iter

FILE = iter.cpp

FLAG = -Wextra -Werror -Wall -Wno-write-strings

all: $(NAME)

$(NAME):
	@clang++ $(FLAG) $(FILE) -o $(NAME)

clean:

fclean: clean
	@rm -rf $(NAME)

re: fclean all
