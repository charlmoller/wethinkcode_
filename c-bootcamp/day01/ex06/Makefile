

CC = clang++
FLAGS = -Wall -Wextra -Werror
NAME = ex06
FILE = main.cpp HumanA.cpp HumanB.cpp Weapon.cpp


all : $(NAME)

$(NAME) :
	@$(CC) $(FLAGS) $(FILE) -o $(NAME)

clean :

fclean : clean
	@rm -rf $(NAME)

re : fclean all

