# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/20 13:47:14 by itiievsk          #+#    #+#              #
#    Updated: 2018/09/20 13:47:20 by itiievsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = clang++

NAME = ft_retro

FLAGS = -Wall -Wextra -Werror

DIR_S = ./

DIR_O = obj

SOURCES =	main.cpp \
			Game.cpp \
			SpaceShip.cpp \
			Enemy.cpp \
			Good.cpp \
			Bullet.cpp \
			Boss.cpp \

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(C) $(FLAGS) -o $(NAME) $(OBJS) -lncurses -lpanel

$(DIR_O)/%.o: $(DIR_S)/%.cpp
	@mkdir -p $(DIR_O)
	$(C) $(FLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
