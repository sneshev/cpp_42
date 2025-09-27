NAME = megaphone
COM = c++
FLAGS = -Wall -Wextra -Werror
SRC = megaphone.cpp 
OBJ = $(SRC:.cpp=.o)
OBJ_DIR = obj/
OBJECTS = $(addprefix $(OBJ_DIR), $(OBJ))

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(COM) $(FLAGS) $(OBJECTS) -o $@

$(OBJ_DIR)%.o : %.cpp
	@mkdir -p $(OBJ_DIR)
	$(COM) $(FLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all re clean fclean
