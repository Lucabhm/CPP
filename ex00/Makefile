NAME = megaphone
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
SRCS = megaphone.cpp
OBJS = $(SRCS:.cpp=.o)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

all:		$(NAME)

clean:
			rm -f *.o

fclean:		clean
			rm -f $(NAME)