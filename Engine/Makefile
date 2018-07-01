#
# EPITECH PROJECT, 2018
# singe
# File description:
# singe
#

NAME		=	raytracer

CC		=	g++

CPPFLAGS	+=	-IInclude
CPPFLAGS	+=	-std=c++17
CPPFLAGS	+=	-Wall -Wextra

SRC 		=	Src/

SRCS		=					\
			$(SRC)Main.cpp 			\
			$(SRC)Color.cpp		\
			$(SRC)Parser.cpp		\
			$(SRC)Vector3f.cpp		\
			$(SRC)StringHelper.cpp		\

OBJS 		=	$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
