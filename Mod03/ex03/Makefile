# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/24 17:18:00 by adantas-          #+#    #+#              #
#    Updated: 2023/12/04 11:26:29 by adantas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET=DiamondTrap
ECHO=/usr/bin/echo -e
YELLOW=\033[1;33m
GREEN=\033[1;32m
RESET=\033[0m

MANDATORY_FLAGS=-Wall -Wextra -Werror --std=c++98

SOURCES=${wildcard source/*.cpp}

${TARGET}: ${SOURCES}
	@${ECHO} "${YELLOW}Compiling $@...${RESET}"
	@c++ ${MANDATORY_FLAGS} -Wno-shadow -Wshadow -Iinclude ${SOURCES} -o $@
	@${ECHO} "${GREEN}Done!${RESET}"

fclean:
	@rm -fr ${TARGET}
	@${ECHO} "${GREEN}Executable removed!${RESET}"
.PHONY: fclean

re: fclean ${TARGET}
.PHONY: re
