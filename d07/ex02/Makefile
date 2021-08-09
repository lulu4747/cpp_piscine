NAME	= Array

SRCS	= main.cpp

INC		= Array.hpp

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
