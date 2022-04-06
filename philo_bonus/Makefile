# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eassofi <eassofi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/26 00:05:41 by eassofi           #+#    #+#              #
#    Updated: 2022/04/06 16:12:59 by eassofi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

CFILES = main.c\
	   philo.c\
	   philo_bonus_utils.c\
	   philo_life.c\
	   create_semaphores.c\
	   check_death_free.c\

SRC = src
INC = inc
HEADER = philo_bonus.h
SOURCES =$(addprefix $(SRC)/, $(CFILES))
HFILES = $(addprefix $(INC)/, $(HEADER))
CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread 
OBJECTS = $(SOURCES:.c=.o)
RM = rm -rf

all : $(NAME)

$(NAME): $(OBJECTS)
		@$(CC) $(CFLAGS) -I $(INC) $(OBJECTS) -o $@
		@echo "\033[0;32mPHILO_BONUS IS READY FOR SIMULATION"

%.o : %.c
	 @$(CC) $(CFLAGS) -I $(INC) -c $< -o $@
clean : 
		@$(RM) $(OBJECTS)
		@echo "\033[0;31m OBJECTS HAS BEEN DELETED"
fclean : clean
		@$(RM) $(NAME)
		@echo "\033[0;31m PHILO HAS BEEN DELETED"

re:fclean all

norm:
	 @norminette src/* inc/*
		