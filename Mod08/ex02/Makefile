# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 13:05:54 by adantas-          #+#    #+#              #
#    Updated: 2024/01/26 17:35:20 by adantas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET=Iterating.exec
ECHO=/usr/bin/echo -e
YELLOW=\033[1;33m
GREEN=\033[1;32m
RESET=\033[0m

MANDATORY_FLAGS=-Wall -Wextra -Werror --std=c++98 -g3

SOURCES=${wildcard source/*.cpp}
INCLUDES=${wildcard include/*.hpp}
EXTRA_DEPS=${wildcard source/*.tpp}

${TARGET}: ${INCLUDES} ${EXTRA_DEPS} ${SOURCES}
	@${ECHO} "${YELLOW}Compiling $@...${RESET}"
	@c++ ${MANDATORY_FLAGS} -Iinclude ${SOURCES} -o $@
	@${ECHO} "${GREEN}Done!${RESET}"

fclean:
	@rm -fr ${TARGET}
	@${ECHO} "${GREEN}Executable removed!${RESET}"
.PHONY: fclean

re: fclean ${TARGET}
.PHONY: re
