

CC = clang++
FLAGS = -Wall -Wextra -Werror
NAME = pony
FILE = main.cpp Pony.cpp


all : $(NAME)

$(NAME) :
	@$(CC) $(FLAGS) $(FILE) -o $(NAME)

clean :

fclean : clean
	@rm -rf $(NAME)

re : fclean all

