# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahabachi ahabachi@student.1337.ma          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/29 18:21:54 by ahabachi          #+#    #+#              #
#    Updated: 2022/10/29 18:21:56 by ahabachi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#                                                                              #
#                                                                              #
#   .___  ___.  __  .__   __.  __  .__________.    ___       __       __  ___  #
#   |   \/   | |  | |  \ |  | |  | |          |   /   \     |  |     |  |/  /  #
#   |  \  /  | |  | |   \|  | |  | `---|  |---`  /  ^  \    |  |     |  '  /   #
#   |  |\/|  | |  | |  . `  | |  |     |  |     /  /_\  \   |  |     |    <    #
#   |  |  |  | |  | |  |\   | |  |     |  |    /  _____  \  |  `----.|  .  \   #
#   |__|  |__| |__| |__| \__| |__|     |__|   /__/     \__\ |_______||__|\__\  #
#                                                                              #
#                                                                              #
#                                                                              #
#  **************************************************************************  #
#   █████████            ██████████         ██████████         ██████████      #
#   ██     ██                    ██                 ██         ██      ██      #
#          ██                    ██                 ██         ██      ██      #
#          ██                    ██                 ██                 ██      #
#          ██            ██████████         ██████████                 ██      #
#          ██                    ██                 ██                 ██      #
#          ██                    ██                 ██                 ██      #
#          ██                    ██                 ██                 ██      #
#       ████████         ██████████         ██████████                 ██      #
#                                                                              #
#  **************************************************************************  #

CFALGS						=	-Wall -Wextra -Werror -I./include
CC							=	cc

MANDATORY_EXEC_CLIENT		=	client
MANDATORY_CLIENT_SOURCES	=	mandatory/client.c\
								mandatory/ft_loadpid.c\
								mandatory/ft_putchar_fd.c\
								mandatory/ft_putstr_fd.c\
								mandatory/ft_strlen.c\
								mandatory/ft_putpid_fd.c\
								mandatory/ft_upload.c
MANDATORY_CLIENT_OBJECTS	=	${MANDATORY_CLIENT_SOURCES:.c=.o}

MANDATORY_EXEC_SERVER		=	server
MANDATORY_SERVER_SOURCES	=	mandatory/server.c\
								mandatory/ft_putpid_fd.c\
								mandatory/ft_putchar_fd.c\
								mandatory/ft_putstr_fd.c\
								mandatory/ft_reset_client.c\
								mandatory/ft_put_client_message.c
MANDATORY_SERVER_OBJECTS	=	${MANDATORY_SERVER_SOURCES:.c=.o}
########################################################################
BONUS_EXEC_CLIENT			=	client_bonus
BONUS_CLIENT_SOURCES		=	bonus/client_bonus.c\
								bonus/ft_loadpid_bonus.c\
								bonus/ft_putchar_fd_bonus.c\
								bonus/ft_putstr_fd_bonus.c\
								bonus/ft_strlen_bonus.c\
								bonus/ft_putpid_fd_bonus.c\
								bonus/ft_upload_bonus.c
BONUS_CLIENT_OBJECTS		=	${BONUS_CLIENT_SOURCES:.c=.o}

BONUS_EXEC_SERVER			=	server_bonus
BONUS_SERVER_SOURCES		=	bonus/server_bonus.c\
								bonus/ft_putpid_fd_bonus.c\
								bonus/ft_putchar_fd_bonus.c\
								bonus/ft_putstr_fd_bonus.c\
								bonus/ft_reset_client_bonus.c\
								bonus/ft_put_client_message_bonus.c
BONUS_SERVER_OBJECTS		=	${BONUS_SERVER_SOURCES:.c=.o}
########################################################################
REMOVE						=	rm -f

%.o:	%.c include/minitalk.h
	${CC} ${CFALGS} -c $< -o $@

all:	${MANDATORY_EXEC_CLIENT} ${MANDATORY_EXEC_SERVER}

bonus:	${BONUS_EXEC_CLIENT} ${BONUS_EXEC_SERVER}

${MANDATORY_EXEC_CLIENT}: ${MANDATORY_CLIENT_OBJECTS}
	${CC} -o ${MANDATORY_EXEC_CLIENT} ${MANDATORY_CLIENT_OBJECTS}

${MANDATORY_EXEC_SERVER}: ${MANDATORY_SERVER_OBJECTS}
	${CC} -o ${MANDATORY_EXEC_SERVER} ${MANDATORY_SERVER_OBJECTS}

${BONUS_EXEC_CLIENT}: ${BONUS_CLIENT_OBJECTS}
	${CC} -o ${BONUS_EXEC_CLIENT} ${BONUS_CLIENT_OBJECTS}

${BONUS_EXEC_SERVER}: ${BONUS_SERVER_OBJECTS}
	${CC} -o ${BONUS_EXEC_SERVER} ${BONUS_SERVER_OBJECTS}

clean:
	${REMOVE} ${MANDATORY_CLIENT_OBJECTS}
	${REMOVE} ${MANDATORY_SERVER_OBJECTS}
	${REMOVE} ${BONUS_CLIENT_OBJECTS}
	${REMOVE} ${BONUS_SERVER_OBJECTS}

fclean: clean
	${REMOVE} ${MANDATORY_EXEC_CLIENT} ${MANDATORY_EXEC_SERVER}
	${REMOVE} ${BONUS_EXEC_CLIENT} ${BONUS_EXEC_SERVER}

norm:
	norminette

re: fclean all

.PHONY: all bonus clean fclean norm re
