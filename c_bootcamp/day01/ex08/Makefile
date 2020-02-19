

CC = clang++
FLAGS = -Wall -Wextra -Werror
NAME = ex08
FILE = main.cpp Human.cpp


all : $(NAME)

$(NAME) :
	@$(CC) $(FLAGS) $(FILE) -o $(NAME)

clean :

fclean : clean
	@rm -rf $(NAME)

re : fclean all

