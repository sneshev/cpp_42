NAME = Sed_is_for_losers
COM = c++
FLAGS = -Wall -Wextra -Werror 

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = includes

SRC =	main.cpp \

OBJ = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	$(COM) $(FLAGS) $(OBJ) -I$(INC_DIR) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(COM) $(FLAGS) -I$(INC_DIR) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re