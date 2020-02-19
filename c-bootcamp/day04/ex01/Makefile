

CC = clang++
FLAGS = -Wall -Wextra -Werror
NAME = ex01
FILE = main.cpp AWeapon.cpp Enemy.cpp Character.cpp \
	PowerFist.cpp PlasmaRifle.cpp RadScorpion.cpp SuperMutant.cpp \


all : $(NAME)

$(NAME) :
	@$(CC) $(FLAGS) $(FILE) -o $(NAME)

clean :

fclean : clean
	@rm -rf $(NAME)

re : fclean all

