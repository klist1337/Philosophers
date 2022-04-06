# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eassofi <eassofi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/12 16:44:30 by eassofi           #+#    #+#              #
#    Updated: 2022/04/06 16:12:43 by eassofi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CFILES= main.c\
 		philo.c\
 		philo_life.c\
   		philo_utils.c\
    	check_death_free.c\

SRC=src
CC= cc
CFLAGS= -Wall -Wextra -Werror -pthread
INC = inc
HEADER = philo.h
SOURCES = $(addprefix $(SRC)/, $(CFILES))
HFILES= $(addprefix $(INC)/, $(HEADER))
OBJECTS = $(SOURCES:.c=.o)
RM= rm -rf



all : $(NAME)

$(NAME): $(OBJECTS)
		@$(CC) $(CFLAGS) -I $(INC) $(OBJECTS)  -o $@
		@echo "\033[0;32mPHILO IS READY FOR SIMULATION"

%.o: %.c $(HFILES)
	 @$(CC) $(CFLAGS) -I $(INC) -c $< -o $@
	

clean:
		@$(RM) $(OBJECTS)
		@echo "\033[0;31m OBJECTS HAS BEEN DELETED"
		

fclean: clean
		@$(RM) $(NAME)
		@echo "\033[0;31m PHILO HAS BEEN DELETED"
re : fclean all

norm:
	 @norminette src/* inc/*
 