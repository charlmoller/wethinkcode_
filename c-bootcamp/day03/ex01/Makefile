

CC = clang++
FLAGS = -Wall -Wextra -Werror
NAME = ex01
FILE = main.cpp FragTrap.cpp ScavTrap.cpp


all : $(NAME)

$(NAME) :
	@$(CC) $(FLAGS) $(FILE) -o $(NAME)

clean :

fclean : clean
	@rm -rf $(NAME)

re : fclean all

