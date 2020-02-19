

CC = clang++
FLAGS = -Wall -Wextra -Werror
NAME = zombie
FILE = main.cpp Zombie.cpp ZombieEvent.cpp


all : $(NAME)

$(NAME) :
	@$(CC) $(FLAGS) $(FILE) -o $(NAME)

clean :

fclean : clean
	@rm -rf $(NAME)

re : fclean all

