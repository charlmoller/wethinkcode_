

CC = clang++
FLAGS = -Wall -Wextra -Werror
NAME = ex03
FILE = main.cpp Bureaucrat.cpp Form.cpp PresidentialPardonForm.cpp \
	ShrubberyCreationForm.cpp RobotomyRequestForm.cpp Intern.cpp


all : $(NAME)

$(NAME) :
	@$(CC) $(FLAGS) $(FILE) -o $(NAME)

clean :

fclean : clean
	@rm -rf $(NAME)

re : fclean all

