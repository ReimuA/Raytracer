#
# EPITECH PROJECT, 2018
# singe
# File description:
# singe
#

NAME		=	libsphere.so
DEST		=	../../Plugins

CC		=	g++

CPPFLAGS	+=	-fPIC
CPPFLAGS	+=	-IInclude
CPPFLAGS	+=	-std=c++17
CPPFLAGS	+=	-Wall -Wextra
CPPFLAGS	+=	-I../../Engine/Include

LDFLAGS		=	-shared

SRC 		=	Src/
ENGINE_SRC 	=	../../Engine/Src/

SRCS		=					\
			$(SRC)Sphere.cpp		\
			$(ENGINE_SRC)Color.cpp		\
			$(ENGINE_SRC)Vector3f.cpp	\

OBJS 		=	$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(LDFLAGS) $(OBJS)
	cp $(NAME) $(DEST)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
