

CC = clang++
FLAGS = -Wall -Wextra -Werror
NAME = test
FILE = tests.cpp Account.class.cpp


all : $(NAME)

$(NAME) :
	@$(CC) $(FLAGS) $(FILE) -o $(NAME)

clean :

fclean : clean
	@rm -rf $(NAME)

re : fclean all

