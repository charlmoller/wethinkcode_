# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ashulha <ashulha@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/13 13:09:02 by ashulha           #+#    #+#              #
#    Updated: 2017/07/13 15:51:06 by ashulha          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = array

FILES = main.cpp

CCFLAGS = -Wall -Wextra -Werror

CLANG = clang++ $(CCFLAGS)

all: $(NAME)

$(NAME):
	@$(CLANG) $(FILES) -o $(NAME)

clean:

fclean: clean
	@rm -rf $(NAME)

re: fclean all
