NAME	= test

SRCS	= Account.cpp
SRCS	+= tests.cpp

INC		= Account.hpp

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


.PHONY:all clean fclean