NAME	= Animals

SRCS	= Animal.cpp
SRCS	+= Cat.cpp
SRCS	+= Dog.cpp
SRCS	+= main.cpp
SRCS	+= WrongAnimal.cpp
SRCS	+= WrongCat.cpp

INC		= Animal.hpp
INC		+= Cat.hpp
INC		+= Dog.hpp
INC		+= WrongAnimal.hpp
INC		+= WrongCat.hpp

OBJ		= $(SRCS:.cpp=.o)

CC		= clang++
CFLAGS	= -std=c++98 -Wall -Werror -Wextra
RM		= rm -f
RM_DIR	= rm -rf

all:
	$(MAKE) $(NAME) --no-print-directory

%.o:%.cpp $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME):$(OBJ) $(INC)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM_DIR) $(OBJ)

fclean:
	$(RM_DIR) $(OBJ)
	$(RM) $(NAME)

re:
	$(MAKE) fclean --no-print-directory
	$(MAKE) all --no-print-directory

.PHONY:all clean fclean re
