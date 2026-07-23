#!/bin/bash

# Usage: ./create.sh ClassName [AnotherClassName ...]

if [ -z "$1" ]; then
  echo "Usage: $0 <ClassName> [AnotherClassName ...]"
  exit 1
fi

progName=$(echo "$1" | tr '[:upper:]' '[:lower:]')

mkdir -p "src" "inc"

#	MAIN FILE (includes every class header)
{
	for className in "$@"; do
		echo "#include \"../inc/${className}.hpp\""
	done
	echo ""
	echo "int main() {"
	echo ""
	echo -e "\treturn (0);"
	echo "}"
} > "src/main.cpp"

for className in "$@"; do

	#	HEADER FILE
	cat > "inc/${className}.hpp" << EOF
#pragma once

#include <iostream>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

class ${className} {
	private:
		
	public:
		${className}();
		${className}(const ${className}& other);
		${className}& operator=(const ${className}& other);
		~${className}();
		
};
EOF

	#	CPP FILE
	cat > "src/${className}.cpp" << EOF
#include "../inc/${className}.hpp"

${className}::${className}() {
	std::cout << GREEN << "${className} Default constructor called" << RESET << std::endl;
}

${className}::${className}(const ${className}& other) {
	std::cout << BLUE << "${className} Copy constructor called" << RESET << std::endl;
	*this = other;
}

${className}& ${className}::operator=(const ${className}& other) {
	std::cout << BLUE << "${className} Copy assignment operator called" << RESET << std::endl;
	if (this != &other) {

	}
	return (*this);
}

${className}::~${className}() {
	std::cout << RED << "${className} Destructor called" << RESET << std::endl;
}
EOF

done

#	Build the SRC list for the Makefile
srcList="\$(SRC_DIR)/main.cpp"
for className in "$@"; do
	srcList="${srcList} \\
		\$(SRC_DIR)/${className}.cpp"
done

#	Makefile
cat > "Makefile" << EOF
NAME = ${progName}
COM = c++
FLAGS = -Wall -Wextra -Werror 

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc

SRC =	${srcList}

OBJ = \$(patsubst \$(SRC_DIR)/%.cpp, \$(OBJ_DIR)/%.o, \$(SRC))

all: \$(NAME)

\$(NAME): \$(OBJ)
	\$(COM) \$(FLAGS) \$(OBJ) -I\$(INC_DIR) -o \$@

\$(OBJ_DIR)/%.o: \$(SRC_DIR)/%.cpp | \$(OBJ_DIR)
	\$(COM) \$(FLAGS) -I\$(INC_DIR) -c \$< -o \$@

\$(OBJ_DIR):
	mkdir -p \$(OBJ_DIR)

clean:
	rm -rf \$(OBJ_DIR)

fclean: clean
	rm -rf \$(NAME)

re: fclean all

.PHONY: all clean fclean re
EOF

echo "Created:"
echo "  Makefile"
echo "  src/main.cpp"
for className in "$@"; do
	echo "  src/${className}.cpp"
	echo "  inc/${className}.hpp"
done