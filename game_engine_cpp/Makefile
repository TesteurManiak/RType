NAME=	game

SRC=	src/main.cpp \
			src/Animation.cpp \
			src/AnimatedSprite.cpp

OBJ=	$(SRC:.cpp=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	g++ $(OBJ) -o $(NAME) -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
