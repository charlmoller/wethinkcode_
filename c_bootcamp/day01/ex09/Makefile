

CC = clang++
FLAGS = -Wall -Wextra -Werror
NAME = ex09
FILE = main.cpp Logger.cpp


all : $(NAME)

$(NAME) :
	@$(CC) $(FLAGS) $(FILE) -o $(NAME)

clean :

fclean : clean
	@rm -rf $(NAME)

re : fclean all

