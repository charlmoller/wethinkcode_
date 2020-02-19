

CC = clang++
FLAGS = -Wall -Wextra -Werror
NAME = ex05
FILE = main.cpp Brain.cpp Human.cpp


all : $(NAME)

$(NAME) :
	@$(CC) $(FLAGS) $(FILE) -o $(NAME)

clean :

fclean : clean
	@rm -rf $(NAME)

re : fclean all

