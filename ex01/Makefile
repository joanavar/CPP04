# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joanavar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/26 12:54:59 by joanavar          #+#    #+#              #
#    Updated: 2025/02/26 13:10:40 by joanavar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	ex00
SRCS		=	Animal.cpp\
				Main.cpp\
				Cat.cpp\
				Dog.cpp\
				WrongAnimal.cpp\
				WrongCat.cpp

CC			=	c++

INCLUDES    =  -I ./ 

RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror -std=c++98

OBJS		=	$(SRCS:.cpp=.o)

%.o: %.cpp
		@$(CC) $(FLAGS) -c $< -o $@ $(INCLUDES)

all: $(NAME)

$(NAME) : $(OBJS) 
		@$(CC) $(CFLAGS) $(OBJS) -o $@ $(INCLUDES)
		@echo '$(NAME) compiled'
fclean: clean
		@$(RM) $(NAME)
clean: 
		@$(RM) $(OBJS)

re: fclean all

.PHONY	: all clean fclean re


