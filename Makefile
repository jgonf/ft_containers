NAMESP	= "ft"
# If the first argument is "ft"...
ifeq (std ,$(firstword $(MAKECMDGOALS)))
  # create the namespace
  NAMESP = "std"
endif


NAME		= ft_containers

CC		= clang++
#CFLAGS	= -Werror -Wextra -Wall -std=c++98 -D NAMESPACE="ft"
CFLAGS	= -Werror -Wextra -Wall -std=c++98 -D NAMESPACE=$(NAMESP)
FSAN	= -Werror -Wextra -Wall -std=c++98 -g -fsanitize=address
RM		= rm -rf

DIR_SRCS	= test/
DIR_OBJS	= objs/
DIR_INC		= ./srcs/

F_SRCS		= main.cpp vector.cpp map.cpp
SRCS		= $(addprefix $(DIR_SRCS), $(F_SRCS))

OBJS		= $(addprefix $(DIR_OBJS), $(F_SRCS:.cpp=.o))

HEADER		= -I $(DIR_INC)

all:		$(NAME)

$(DIR_OBJS)%.o: $(DIR_SRCS)%.cpp
		$(CC) $(CFLAGS) $(NAMESPACE) $(HEADER) -c $< -o $@

$(NAME):	$(DIR_OBJS) $(OBJS)
		${CC} $(CFLAGS) $(NAMESPACE) $(OBJS) -o $(NAME)

$(DIR_OBJS):
		@mkdir $(DIR_OBJS)

std:	re

clean:
		$(RM) $(DIR_OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:     all re clean fclean
