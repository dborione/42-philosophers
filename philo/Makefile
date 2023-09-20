# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dborione <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/01 12:42:50 by dborione          #+#    #+#              #
#    Updated: 2023/05/01 12:43:30 by dborione         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	Compiler
CC = gcc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=thread 

#	Sources
FILES = main.c print_msg.c initialise.c	\
		routine.c parsing.c end_sim.c \
		atoi.c time_utils.c print_error.c check_death.c \

SRCS = $(addprefix src/, $(FILES))

#	Objects
OBJS = $(SRCS:.c=.o)

#	Others
NAME = philo
RM = rm -f

#	Colours
GREEN = \033[32m
YELLOW = \033[33m
RED = \033[31m
DEFAULT = \033[0m

#	Targets
all :	$(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)[Done!]$(DEFAULT)"

#	Cleaning
clean:
	@echo "$(YELLOW)[Cleaning...]$(DEFAULT)"
	$(RM) $(OBJS)
	@echo "$(RED)[Objects Cleaned!]$(DEAFULT)"

fclean: clean
	$(RM) $(NAME)
	@echo "$(RED)[Executable File Cleaned!]$(DEFAULT)"

re: fclean all

.PHONY:	clean fclean re all bonus
