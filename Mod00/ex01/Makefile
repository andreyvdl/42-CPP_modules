# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/31 16:26:40 by adantas-          #+#    #+#              #
#    Updated: 2023/11/06 11:52:17 by adantas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET=phonebook.exec
ECHO=/usr/bin/echo -e
YELLOW=\033[1;33m
GREEN=\033[1;32m
RESET=\033[0m

SOURCES=${wildcard source/*.cpp}

${TARGET}: ${SOURCES}
	@${ECHO} "${YELLOW}Compiling $@...${RESET}"
	@c++ -Wall -Wextra -Werror --std=c++98 -Iinclude ${SOURCES} -o $@
	@${ECHO} "${GREEN}Done!${RESET}"

fclean:
	@rm -fr ${TARGET}
	@${ECHO} "${GREEN}Executable removed!${RESET}"
.PHONY: fclean

re: fclean ${TARGET}
.PHONY: re
