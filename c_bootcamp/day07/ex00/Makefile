# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ashulha <ashulha@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/12 14:06:10 by ashulha           #+#    #+#              #
#    Updated: 2017/07/12 14:24:44 by ashulha          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = template

FILE = whatever.cpp

CCFLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@clang++ $(CCFLAG) $(FILE) -o $(NAME)

clean:

fclean: clean
	@rm -rf $(NAME)

re: fclean all
