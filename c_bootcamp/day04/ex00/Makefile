

CC = clang++
FLAGS = -Wall -Wextra -Werror
NAME = ex00
FILE = main.cpp Sorcerer.cpp Peon.cpp Victim.cpp


all : $(NAME)

$(NAME) :
	@$(CC) $(FLAGS) $(FILE) -o $(NAME)

clean :

fclean : clean
	@rm -rf $(NAME)

re : fclean all

