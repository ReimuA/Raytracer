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

LDFLAGS		=	-ldl

SRC 		=	Src/

SRCS		=					\
			$(SRC)Ray.cpp 			\
			$(SRC)Main.cpp 			\
			$(SRC)Color.cpp			\
			$(SRC)DlHelper.cpp		\
			$(SRC)Parser.cpp		\
			$(SRC)Vector3f.cpp		\
			$(SRC)StringHelper.cpp		\
			$(SRC)ObjectFactory.cpp		\

OBJS 		=	$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
