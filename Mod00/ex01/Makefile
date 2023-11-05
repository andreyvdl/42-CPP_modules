# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/31 16:26:40 by adantas-          #+#    #+#              #
#    Updated: 2023/11/05 19:16:53 by adantas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET=phonebook.exec
ifeq (${shell echo -e}, -e)
	ECHO=echo
else
	ECHO=echo -e
endif
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
