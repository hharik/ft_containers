CC = c++
FLAGS = -Wall -Wextra -Werror  -std=c++98

NAME_VECTOR = vector
NAME_MAP = map
NAME_STACK = stack
NAME_MAIN = main

VECTOR_SRC = vector_main.cpp
MAP_SRC = map_main.cpp
STACK_SRC = stack_main.cpp
MAIN_SRC = main.cpp

vector: $(NAME_VECTOR)
$(NAME_VECTOR) : $(VECTOR_SRC)
	@$(CC) $(FLAGS) $(VECTOR_SRC) -o $(NAME_VECTOR)


map : $(NAME_MAP)
$(NAME_MAP) : $(MAP_SRC)
	@$(CC) $(FLAGS) $(MAP_SRC) -o $(NAME_MAP)


stack : $(NAME_STACK)
$(NAME_STACK) : $(STACK_SRC)
	@$(CC) $(FLAGS) $(STACK_SRC) -o $(NAME_STACK)

main : $(NAME_MAIN)
$(NAME_MAIN) : $(MAIN_SRC)
	@$(CC) $(FLAGS) $(MAIN_SRC) -o $(NAME_MAIN)

all : vector map stack main

clean:
	@rm -rf there_test_file my_test_file


fclean : clean
	@rm -rf $(NAME_VECTOR) $(NAME_MAP) $(NAME_STACK) $(NAME_MAIN) there_test_file my_test_file


re : fclean all