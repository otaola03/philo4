# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/12 14:10:40 by jperez            #+#    #+#              #
#    Updated: 2023/02/28 17:19:38 by jperez           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


define HEADER
░░░░░██╗██████╗░███████╗██████╗░███████╗███████╗
░░░░░██║██╔══██╗██╔════╝██╔══██╗██╔════╝╚════██║
░░░░░██║██████╔╝█████╗░░██████╔╝█████╗░░░░███╔═╝
██╗░░██║██╔═══╝░██╔══╝░░██╔══██╗██╔══╝░░██╔══╝░░
╚█████╔╝██║░░░░░███████╗██║░░██║███████╗███████╗
░╚════╝░╚═╝░░░░░╚══════╝╚═╝░░╚═╝╚══════╝╚══════╝

endef
export HEADER

NAME = philo
NAME_BONUS = philo_bonus

#Mandatory files
S = mandatory/srcs/
O = mandatory/objs/

#Bonus files
BS = bonus/srcs/
BO = bonus/objs/

F = -fsanitize=address

CC = gcc -O3 -g3 $(F) 
#CFLAGS = -Wall -Werror -Wextra

RM = -rm -rf


SRCS = $Smain.c $Sft_aux.c $Sft_create_mutex.c $Sft_save_param.c $Sft_manage_threads.c \
	   $Sft_philo_action.c $Sft_initialice_philo.c $Sft_manage_time.c $Sft_dealer.c \
	   $Sft_general_free.c $Sft_print.c

OBJS = $Omain.o $Oft_aux.o $Oft_create_mutex.o $Oft_save_param.o $Oft_manage_threads.o \
	   $Oft_philo_actions.o $Oft_initialice_philo.o $Oft_manage_time.o $Oft_dealer.o \
	   $Oft_general_free.o $Oft_print.o

SRCS_BONUS = $(BS)main.c $(BS)ft_aux.c $(BS)ft_create_forks.c $(BS)ft_general_free.c $(BS)ft_initialice_philo.c \
		$(BS)ft_manage_time.c $(BS)ft_philo_actions.c $(BS)ft_save_param.c $(BS)ft_manage_sem.c $(BS)ft_cheff.c $(BS)ft_print.c

OBJS_BONUS = $(BO)main.o $(BO)ft_aux.o $(BO)ft_create_forks.o $(BO)ft_general_free.o $(BO)ft_initialice_philo.o \
		$(BO)ft_manage_time.o $(BO)ft_philo_actions.o $(BO)ft_save_param.o $(BO)ft_manage_sem.o $(BO)ft_cheff.o $(BO)ft_print.o

# ---------- CREATE OBJECTS FOLDERS ----------

all: $(NAME)

$O:
	@echo "Creating Objects Folder...."
	mkdir $@
	@echo "Folder created."

$(OBJS): | $O

$(BO):
	@echo "Creating Objects Folder...."
	mkdir $@
	@echo "Folder created."

$(OBJS_BONUS): | $(BO)

# ---------- CREATE OBJECTS ----------

$(OBJS): $O%.o: $S%.c
	$(CC) $(CFLAGS) -O3 -c $< -o $@

$(OBJS_BONUS): $(BO)%.o: $(BS)%.c
	$(CC) $(CFLAGS) -O3 -c $< -o $@

# ---------- NAME ----------

$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(NAME_BONUS)
	@echo "\033[0;33m"
	@echo "$$HEADER"

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "\033[0;33m"
	@echo "$$HEADER"

bonus: $(NAME_BONUS)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS) $O $(BO)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: fclean clean all
