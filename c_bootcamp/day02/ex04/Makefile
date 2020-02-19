

CC = clang++
FLAGS = -Wall -Wextra -Werror
NAME = eval_expr
FILE = main.cpp Fixed.class.cpp


all : $(NAME)

$(NAME) :
	@$(CC) $(FLAGS) $(FILE) -o $(NAME)

clean :

fclean : clean
	@rm -rf $(NAME)

re : fclean all

