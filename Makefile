NAME		= ft_containers

CC		= clang++-9
CFLAGS		= -Werror -Wextra -Wall -std=c++98
RM		= rm -rf

DIR_SRCS	= test/
DIR_OBJS	= objs/
DIR_INC		= ./srcs/

#F_SRCS		= ite_n1.cpp
F_SRCS		= vector.cpp
#F_SRCS		= reverse_iterator.cpp
SRCS		= $(addprefix $(DIR_SRCS), $(F_SRCS))

OBJS		= $(addprefix $(DIR_OBJS), $(F_SRCS:.cpp=.o))

HEADER		= -I $(DIR_INC)

all:		$(NAME)

$(DIR_OBJS)%.o: $(DIR_SRCS)%.cpp
		$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(NAME):	$(DIR_OBJS) $(OBJS)
		${CC} $(CFLAGS) $(OBJS) -o $(NAME)

$(DIR_OBJS):
		@mkdir $(DIR_OBJS)

clean:
		$(RM) $(DIR_OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:     all re clean fclean
