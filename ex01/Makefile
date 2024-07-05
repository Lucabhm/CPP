NAME = phonebook
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

all:			$(NAME)

clean:
				rm -f *.o

fclean:			clean
				rm -f $(NAME)

re:				fclean all

.PHONY:			all clean fclean re