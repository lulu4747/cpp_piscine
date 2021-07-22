NAME	= Bureaucrat

SRCS	= Bureaucrat.cpp
SRCS	+= Form.cpp
SRCS	+= main.cpp
SRCS	+= PresidentialPardonForm.cpp
SRCS	+= RobotomyRequestForm.cpp
SRCS	+= ShrubberyCreationForm.cpp

INC		= Bureaucrat.hpp
INC		+= Form.hpp
INC		+= PresidentialPardonForm.hpp
INC		+= RobotomyRequestForm.hpp
INC		+= ShrubberyCreationForm.hpp

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
