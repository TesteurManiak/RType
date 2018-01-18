NAME=	game

SRC=	src/main.cpp \
			src/Animation.cpp \
			src/AnimatedSprite.cpp \
			src/Background.cpp \
			src/Spaceship.cpp \
			src/gameSound.cpp \
			src/EvilSpaceship.cpp

OBJ=	$(SRC:.cpp=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	g++ $(OBJ) -o $(NAME) -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system -W -Wall -Werror

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
