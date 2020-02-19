

CC = clang++ 
FLAGS = -Wall -Wextra -Werror
NAME = ex02
FILE = main.cpp ClapTrap.cpp FragTrap.cpp ScavTrap.cpp


all : $(NAME)

$(NAME) :
	@$(CC) $(FLAGS) $(FILE) -o $(NAME)

clean :

fclean : clean
	@rm -rf $(NAME)

re : fclean all

