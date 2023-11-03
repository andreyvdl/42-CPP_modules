# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/31 16:26:40 by adantas-          #+#    #+#              #
#    Updated: 2023/10/31 17:19:39 by adantas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET=phonebook
ECHO=echo
YELLOW=\033[1;33m
GREEN=\033[1;32m
RESET=\033[0m

SOURCES=${wildcard source/%.cpp}

${TARGET}: ${SOURCES}
	@${ECHO} "${YELLOW}Compiling $@...${RESET}"
	@c++ -Wall -Wextra -Werror --std=c++98 -I./include ${SOURCES} -o $@
	@${ECHO} "${GREEN}Done!${RESET}"

fclean:
	@rm -fr ${TARGET}
	@${ECHO} "${GREEN}Executable removed!${RESET}"
.PHONY: fclean

re: fclean ${TARGET}
.PHONY: re

# tests: ${TARGET}
# # PDF TESTS
# 	@${ECHO} "${YELLOW}PDF tests:${RESET}"
# 	./${TARGET} "shhhhh... I think the students are asleep..."
# 	./${TARGET} Damnit " ! " "Sorry students, I thought this thing was off."
# 	./${TARGET}
# # MY TESTS
# 	@${ECHO} "${YELLOW}My tests:${RESET}"
# 	./${TARGET} "THE " one piece " IS real!"
# 	./${TARGET} "omaewa " "mou shin"           deiru!
# 	./${TARGET} "can you hear the silence? can you see the dark? can you fix the broken? CAN YOU FELL MY HEART?"
# .PHONY: tests
