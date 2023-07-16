NAME 	= 	AccountLog
CC		=	c++
CFLAGS	=	-Wall -Wextra -Werror
STD		=	-std=c++98

SRC		= 	$(wildcard *.cpp)
OBJ		=	$(SRC:.cpp=.o)

all	 :	$(NAME)

$(NAME)	:	$(OBJ)
	$(CC) $(CFLAGS) $(STD) $(OBJ) -o $(NAME)

%.o : %.cpp
	$(CC) $(CFLAGS) $(STD) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : 		clean
	rm -f $(NAME)

re	 : 	fclean all

.PHONY: all clean fclean re