NAME	= Abstract

SRCS	= AAnimal.cpp
SRCS	+= Brain.cpp
SRCS	+= Cat.cpp
SRCS	+= Dog.cpp
SRCS	+= main.cpp

INC		= AAnimal.hpp
INC		+= Brain.hpp
INC		+= Cat.hpp
INC		+= Dog.hpp

OBJ		= $(SRCS:.cpp=.o)

CC		= clang++
CFLAGS	= -Wall -Werror -Wextra
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
