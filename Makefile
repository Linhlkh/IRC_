# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khle <khle@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/21 05:27:18 by khle              #+#    #+#              #
#    Updated: 2024/03/21 05:27:56 by khle             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		=	irc	
CC			=	c++
FLAGS		=	-Wall -Wextra -Werror -MMD -std=c++98
INCLUDES	=	-I $(HEADER)

SRC_PATH	=	sources/
HEADER		=	includes/
OBJ_PATH	=	objs/

SOURCES		=	main.cpp \

SRCS		=	$(addprefix $(SRC_PATH),$(SOURCES))
OBJS		=	$(addprefix $(OBJ_PATH),$(SOURCES:.cpp=.o))
DEPS		=	$(addprefix $(OBJ_PATH),$(SOURCES:.cpp=.d))	


all: tmp $(NAME)


tmp:
		@mkdir -p $(OBJ_PATH)

$(NAME): $(OBJS) Makefile
		$(CC) $(FLAGS) $(INCLUDES) $(OBJS) -o $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
		$(CC) $(FLAGS) -c $< -o $@

clean:
		@$(RM) $(OBJ_PATH)
			
fclean: clean
		@$(RM) $(NAME)

re: fclean all

RM			=	rm -rf

-include $(DEPS)

.PHONY: all clean fclean re 