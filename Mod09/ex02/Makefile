# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 13:05:54 by adantas-          #+#    #+#              #
#    Updated: 2024/02/07 11:09:10 by adantas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=PmergeMe
ECHO=/usr/bin/echo -e
YELLOW=\033[1;33m
GREEN=\033[1;32m
RESET=\033[0m

MANDATORY_FLAGS=-Wall -Wextra -Werror -std=c++98 -g3

SOURCES=${wildcard source/*.cpp}
INCLUDES=${wildcard include/*.hpp}
EXTRA_DEPS=${wildcard source/*.tpp}
OBJECTS=${addprefix object/, ${notdir ${SOURCES:.cpp=.o}}}

VPATH=source

all: ${NAME}
.PHONY: all

${NAME}: ${OBJECTS}
	@${ECHO} "${YELLOW}Compiling $@...${RESET}"
	@c++ ${MANDATORY_FLAGS} -Iinclude ${OBJECTS} -o $@
	@${ECHO} "${GREEN}Done!${RESET}"

object/%.o: %.cpp | object 
	@${ECHO} "${YELLOW}Compiling $@...${RESET}"
	@c++ ${MANDATORY_FLAGS} -Iinclude -c $< -o $@

object:
	@mkdir -p object

clean:
	@rm -fr object
.PHONY: clean

fclean: clean
	@rm -fr ${NAME}
	@${ECHO} "${GREEN}Executable removed!${RESET}"
.PHONY: fclean

re: fclean all
.PHONY: re
