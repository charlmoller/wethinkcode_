
CC = clang++
FLAGS = -lncurses
NAME = ft_gkrellm
FILE = main.cpp Monitor.cpp TimeModule.cpp HostModule.cpp OSInfoModule.cpp \
	CPUModule.cpp RAMModule.cpp NetworkModule.cpp


all : $(NAME)

$(NAME) :
	@$(CC) $(FLAGS) $(FILE) -o $(NAME)

clean :

fclean : clean
	@rm -rf $(NAME)

re : fclean all
