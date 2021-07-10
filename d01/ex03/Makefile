NAME	= test

SRCS	= HumanA.cpp
SRCS	+= HumanB.cpp
SRCS	+= main.cpp
SRCS	+= Weapon.cpp

INC		= HumanA.hpp
INC		= HumanB.hpp
INC		= Weapon.hpp

OBJ		= $(SRCS:.cpp=.o)

CC		= clang++
CFLAGS	= -Wall -Werror -Wextra
RM		= rm -f
RM_DIR	= rm -rf

all:
	$(MAKE) $(NAME) --no-print-directory

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